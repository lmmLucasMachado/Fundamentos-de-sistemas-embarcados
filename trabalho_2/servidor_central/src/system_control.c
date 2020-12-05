#include "../inc/system_control.h"

int sock_fd, conect_fd;

void init_server(){
    struct sockaddr_in servaddr;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock_fd == -1)
        printf("socket creation failed...\n");
    else
        printf("Socket successfully created..\n");
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(SERVIDOR_DISTRIBUIDO); 
    servaddr.sin_port = htons(PORT_D); 

    // connect the client socket to server socket 
    if (connect(sock_fd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n");

}

int lamp[5], air[3], alarm_;
double temp, hum;

void get_json(){
    char buffer[MAX_MSG];

    //pega msg do socket
    read(sock_fd, buffer, sizeof(buffer));

    //printf("Menssage:\n %s", buffer);

    //mock_json(buffer);
    
//    printf("%s\n",buffer);
    
    cJSON *json = cJSON_Parse(buffer);

    cJSON* item;
    
    // get lamp
    item = cJSON_GetObjectItemCaseSensitive(json, "lamp_1");
    lamp[0] = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "lamp_2");
    lamp[1] = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "lamp_3");
    lamp[2] = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "lamp_4");
    lamp[3] = cJSON_GetNumberValue(item);

    // get air
    item = cJSON_GetObjectItemCaseSensitive(json, "air_1");
    air[0] = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "air_2");
    air[1] = cJSON_GetNumberValue(item);

    // get temp
    item = cJSON_GetObjectItemCaseSensitive(json, "temp");
    temp = cJSON_GetNumberValue(item);

    // get hum
    item = cJSON_GetObjectItemCaseSensitive(json, "hum");
    hum = cJSON_GetNumberValue(item);

    // get status alarm
    item = cJSON_GetObjectItemCaseSensitive(json, "alarm");
    alarm_ = cJSON_GetNumberValue(item);

    cJSON_Delete(json);

}

double get_temp(){
    return temp;
}

double get_hum(){
    return hum;
}

int get_alarm(){
    return alarm_;
}

int *get_lamp(){

    int *data = (int*)malloc(4*sizeof(int));

    data[0] = lamp[0];
    data[1] = lamp[1];
    data[2] = lamp[2];
    data[3] = lamp[3];

    return data;
}

int *get_air(){

    int *data = (int*)malloc(2*sizeof(int));

    data[0] = air[0];
    data[1] = air[1];

    return data;
}

double temp_wish;
void set_temp_wish(double temp_w){

    temp_wish = temp_w;

}

int control_air(){
    if ((temp_wish - 1) < temp  && (temp_wish + 1) > temp) 
        return 0;
    else 
        return 1;
}

int disp_wish;
void set_disp_wish(int disp_w){
    disp_wish = disp_w;
}

int alarm_wish;
void set_alarm(int alarm_w){
    if (alarm_w != 1|| alarm_w != 0)
        printf("Opcao invalida!");
    else
        alarm_ = alarm_w;
}

void server_listen(){
    while(1){
        if (conect_fd < 0) { 
            printf("server acccept failed...\n"); 
            exit(0); 
        } 
        else{
            //printf("server acccept the client...\n"); 
            sleep(0.120);
            get_json();
        }
    }
}

int sock_fd2;

void server_write(int signal){

    // Call menu
    menu();
    
    struct sockaddr_in servaddr;

    sock_fd2 = socket(AF_INET, SOCK_STREAM, 0); 

    if (sock_fd2 == -1)
        printf("socket creation failed...\n"); 
    else
        printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(SERVIDOR_CENTRAL);
    servaddr.sin_port = htons(PORT_D); 

    char message[MAX_MSG];
    printf("\nEscrevendo\n");
    
    int err = connect(sock_fd2, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(err < 0) {
        close(sock_fd2);
    }
    
    int air_1, air_2;

    if (disp_wish > 4 && disp_wish < 7 && control_air() != 0){
        if (disp_wish == 5)
            air_1 = 0;
        else
            air_2 = 0;
    }else
        lamp[disp_wish - 1] = 0;

    if (control_air() == 0){
        air_1 = 0;
        air_2 = 0;
    }
    
    sprintf(message,
    "{ \"lamp_1\": %d, \"lamp_2\": %d, \"lamp_3\": %d,\n \"lamp_4\": %d, \"air_1\": %d, \"air_2\": %d }",
    lamp[0], lamp[1], lamp[2], lamp[3], air_1, air_2);

    send(sock_fd, message, MAX_MSG,0);

    close(sock_fd2);

    // Mantendo dados CSV
    maintain_data_csv();

    alarm(1);
}

void init_maintain_data(){
    printf("mantendo");

    FILE *p_file;
    p_file = fopen ("./doc/data.csv", "w+");
    fprintf(p_file, "\"Data\",\"Hora\",\"Temperatura\",\"Umidade\",\"Lampada Cozinha\",\"Lampada Sala\",\"Lampada Quarto 1\",\"Lampada Quarto 2\",\"Ar-condicionado 1\",\"Ar-condicionado 2\",\"Alarme\"\n");
    fclose(p_file);

}

void maintain_data_csv(){
    struct tm *date_hour;     
    time_t segundos;
    time(&segundos);

    date_hour = localtime(&segundos);  

    FILE *p_file;
    p_file = fopen ("./doc/data.csv", "a+");
    fprintf(p_file,"\"%d/%d/%d\",", date_hour->tm_mday, date_hour->tm_mon+1,date_hour->tm_year+1900);
    fprintf(p_file,"\"%d:%d:%d\",", date_hour->tm_hour, date_hour->tm_min, date_hour->tm_sec);
    fprintf(p_file, "\"%0.2lf\",\"%0.2lf\"\n", temp, hum);
    fprintf(p_file, "\"%d\",\"%d\",\"%d\",\"%d\",", lamp[0],lamp[1],lamp[2],lamp[3]);
    fprintf(p_file, "\"%d\",\"%d,\"%d\",\"%d\",\"%d\",\"%d\",", air[0],air[1],alarm_);
    
    fclose(p_file);

    //printf("\n\nEscrevendo csv\n\n");
    alarm(1);
}