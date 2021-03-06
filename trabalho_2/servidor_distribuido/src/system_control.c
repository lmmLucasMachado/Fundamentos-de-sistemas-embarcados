#include "../inc/system_control.h"

int sock_fd;

void init_server_listen(){
    struct sockaddr_in servaddr;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock_fd == -1)
        printf("socket creation failed...\n"); 
    else
        printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT_D); 

    // Binding newly created socket to given IP and verification 
    if ((bind(sock_fd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification 
    if ((listen(sock_fd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    }else
        printf("Server listening..\n");

}

/*
void mock_json(char *msg) {
    FILE *arq;
    char Linha[100];
    char *result;
    int i,j=0,a=0;

    // Abre um arquivo TEXTO para LEITURA
    arq = fopen("./exem_json.txt", "r");
    
    if (arq == NULL) {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    i = 1;
    while (!feof(arq))
    {
    // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        while(result[j] != '\n'){
            msg[a] = result[j];
            a++;
            j++;
        }

        j=0;
        i++;
    }
  fclose(arq);
}
*/

int lamp[5], air[3], status_sens[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void get_json(int p_sock_fd){
    char buffer[MAX_MSG];
    //pega msg do socket
    read(p_sock_fd, buffer, sizeof(buffer));

    printf("\nMenssage recebida: %s\n", buffer);

    //mock_json(buffer);
        
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

    cJSON_Delete(json);

}


void init_maintain_data(){
    printf("mantendo");

    FILE *p_file;
    p_file = fopen ("./doc/data.csv", "w+");
    fprintf(p_file, "\"Data\",\"Hora\",\"Temperatura\",\"Umidade\",\"Lampada Cozinha\",\"Lampada Sala\",\"Lampada Quarto 1\",\"Lampada Quarto 2\",\"Ar-condicionado 1\",\"Ar-condicionado 2\",\"Sensor presenca sala\",\"Sensor presenca Cozinha\",\"Prota cozinha\",\"Janela cozinha\",\"Prota sala\",\"Janela sala\",\"Janela quarto 1\",\"Janela quarto 2\"\n");
    fclose(p_file);

}

double *data;
double temp, hum;

void maintain_data_csv(){
    // enviar sevidor central
/*
    int i;
    for (i=0;i<2;i++)
        printf("vetor %d: %lf\n",i,data[i]);
*/  
    data = get_data();
    temp = data[0];
    hum = data[1];
    //printf("%lf %lf ", temp, hum);
    free(data);

    struct tm *date_hour;     
    time_t segundos;
    time(&segundos);

    date_hour = localtime(&segundos);  

    FILE *p_file;
    p_file = fopen ("./doc/data.csv", "a+");
    fprintf(p_file,"\"%d/%d/%d\",", date_hour->tm_mday, date_hour->tm_mon+1,date_hour->tm_year+1900);
    fprintf(p_file,"\"%d:%d:%d\",", date_hour->tm_hour, date_hour->tm_min, date_hour->tm_sec);
    fprintf(p_file, "\"%0.2lf\",\"%0.2lf\",", temp, hum);
    fprintf(p_file, "\"%d\",\"%d\",\"%d\",\"%d\",", lamp[0],lamp[1],lamp[2],lamp[3]);
    fprintf(p_file, "\"%d\",\"%d,\"%d\",\"%d\",\"%d\",\"%d\",", air[0],air[1],status_sens[0],status_sens[1],status_sens[2],status_sens[3]);
    fprintf(p_file, "\"%d\",\"%d,\"%d\",\"%d\"\n", status_sens[4],status_sens[5],status_sens[6],status_sens[7]);
    
    fclose(p_file);

    //printf("\n\nEscrevendo csv\n\n");
    alarm(1);
}

int status_sensor(){
    int i, buffer;
    int alarm_on = 1;

    for (i = 0;i < 8;i++){
        buffer = get_sensor(i);
        
        if (status_sens[i] == alarm_on){
            //push pra central
            printf("\nAlarme acionado!!!\n");
            status_sens[i] = buffer;
            break;
        }else
            status_sens[i] = buffer;
    }
    return buffer;
}

int send_socket;

void server_write(){

    struct sockaddr_in servaddr;

    send_socket = socket(AF_INET, SOCK_STREAM, 0); 

    if (send_socket == -1)
        printf("socket creation failed...\n"); 
    else
        printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(SERVIDOR_CENTRAL);
    servaddr.sin_port = htons(PORT_C); 

    char message[MAX_MSG];
    
    int err = connect(send_socket, (struct sockaddr*)&servaddr, sizeof(servaddr));

    if(err < 0) {
        printf("\nClose socket send.\n");
        close(send_socket);
        return;
    }
    
    sprintf(message,
    "{ \"lamp_1\": %d, \"lamp_2\": %d, \"lamp_3\": %d,\n \"lamp_4\": %d, \"air_1\": %d, \"air_2\": %d, \"temp\": %0.2lf,  \"hum\": %0.2lf,  \"alarm\": %d }",
    lamp[0], lamp[1], lamp[2], lamp[3], air[0], air[1], temp, hum, status_sensor() );

    printf("\nMenssagem enviada: %s\n",message);

    // send message for server central
    err = send(send_socket, message, MAX_MSG, 0);

    if(err <= 0) {
        fprintf(stderr, "Error sending alarm package\n");
        exit(-1);
    }
    printf("\n%s\n",message);

    // Close socket
    close(send_socket);

    // Maintain data CSV
    maintain_data_csv();

    alarm(1);

}

void *server_listen(void *args){

    printf("\nLendo\n");
    
    while(1){
        // Accept the data packet from client and verification 
        int conect_fd = accept(sock_fd, NULL, NULL);

        if (conect_fd < 0) {
            printf("\nserver acccept failed...\n"); 
            continue; 
        }else{
            printf("\nserver acccept the client...\n"); 
            get_json(conect_fd);
            close(conect_fd);
        }

        int i;
        // lamp on/off
        //printf("\n     AQUI     \n");
        for(i = 0;i < 4;i++){
            if (lamp[i] == 1)
                set_high_gpio(i);
            else if(lamp[i] == 0)
                set_low_gpio(i);
        }

        // air on/off
        for(i = 0;i < 2;i++){
            if (air[i] == 1)
                set_high_gpio(i + 4);
            else if(air[i] == 0)
                set_low_gpio(i + 4);
        }
    }
}
