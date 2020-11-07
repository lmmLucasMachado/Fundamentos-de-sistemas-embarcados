#include "../inc/system_control.h"

int sock_fd;

void init_server(){

    int conect_fd;
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
    servaddr.sin_port = htons(PORT_C); 
    printf("vai iniciar");

    // Now server is ready to listen and verification 
    if ((listen(sock_fd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    }
    else
        printf("Server listening..\n"); 
}

int lamp[5], air[3], status_sens;
double temp, hum;

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

    item = cJSON_GetObjectItemCaseSensitive(json, "temp");
    temp = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "hum");
    hum = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "alarm");
    alarm = cJSON_GetNumberValue(item);

    cJSON_Delete(json);

}