#include "../inc/system_control.h"

void init_socket(){

    printf("vai iniciar");

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


void get_json(int* lamp, int* air) {

    //pegar msg do socket
    char buffer[MAX_MSG];

    mock_json(buffer);
    
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
    int i, buffer, status;
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