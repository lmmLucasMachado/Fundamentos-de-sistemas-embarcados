#include "../inc/system_control.h"

int sock_fd;

void init_server(){

    int connfd, len; 
    struct sockaddr_in servaddr, cli; 

    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock_fd == -1)
        printf("socket creation failed...\n"); 
    else
        printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT_D); 
    printf("vai iniciar");

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
    }
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 

    // Accept the data packet from client and verification 
    connfd = accept(sock_fd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 


}

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


void get_json(int* lamp, int* air){

    char buffer[MAX_MSG];

    //pega msg do socket
    read(sock_fd, buffer, MAX_MSG);

    printf("Menssage:\n %s", buffer);

    //mock_json(buffer);
    
    printf("%s\n",buffer);
    
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

void status_sensor(int *status){
    int i, buffer;
    for (i = 0;i < 8;i++){
        buffer = get_sensor(i);
        
        if (buffer != status[i]){
            //push pra central
            printf("Aciona alarm!!!");
            break;
        }else{
            status[i] = buffer;
        }
    
    }

}

void *set_gpio(void* args){
    
    int lamp[5], air[3], status[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    
    while(1){
        sleep(0.100);
        get_json(lamp, air);

        int i;
        // lamp on/off
        printf("\nAQUI\n");
        for(i = 0;i < 4;i++){
            if (lamp[i] == 0)
                set_high_gpio(i);

            else if(lamp[i] == 1)
                set_low_gpio(i);
        }

        // air on/off
        for(i = 0;i < 2;i++){
            if (air[i] == 0)
                set_high_gpio(i + 4);
            else if(air[i] == 1)
                set_low_gpio(i + 4);
        }
    }
}

void maintain_data_csv(){

    double *data;

    //data[0]=temp;
    //data[1]=hum;
    data = get_data();
    
    // enviar sevidor central
    int i;
    for (i=0;i<2;i++)
        printf("vetor %d: %lf\n",i,data[i]);
    
    struct tm *date_hour;     
    time_t segundos;
    time(&segundos);

    date_hour = localtime(&segundos);  

    FILE *p_file;
    p_file = fopen ("./doc/data.csv", "a+");
    fprintf(p_file,"\"%d/%d/%d\",", date_hour->tm_mday, date_hour->tm_mon+1,date_hour->tm_year+1900);
    fprintf(p_file,"\"%d:%d:%d\",", date_hour->tm_hour, date_hour->tm_min, date_hour->tm_sec);
    fprintf(p_file, "\"%0.2lf\",\"%0.2lf\"\n", data[0], data[1]);
    fclose(p_file);

    //printf("\n\nEscrevendo csv\n\n");
    alarm(2);

}