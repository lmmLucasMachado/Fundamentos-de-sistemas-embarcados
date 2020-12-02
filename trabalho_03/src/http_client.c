#include <string.h>
#include <stdlib.h>
#include "esp_event.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/task.h"


#include "http_client.h"
#include "./cJSON.h"

#define TAG "HTTP"

static char response[MAX_MSG];
double temp_atual, temp_max, temp_min, humidity;

esp_err_t _http_event_handle(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER");
            printf("%.*s", evt->data_len, (char*)evt->data);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            if (!esp_http_client_is_chunked_response(evt->client))
                printf("%.*s", evt->data_len, (char*)evt->data);
            break;
        case HTTP_EVENT_ON_FINISH:
            esp_http_client_read(evt->client, response, MAX_MSG);
            ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
            get_json();
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
    }
    return ESP_OK;
}

void http_request_ip(){
    esp_http_client_config_t config = {
        .url = "http://api.ipstack.com/check?access_key=eead118251aa33d80ccd722e5103dbaa",
        .event_handler = _http_event_handle,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
    ESP_LOGI(TAG, "Status = %d, content_length = %d",
            esp_http_client_get_status_code(client),
            esp_http_client_get_content_length(client));
    }

    esp_http_client_cleanup(client);
}

void https_request()
{
    esp_http_client_config_t config = {
        .url = "https://covid19-brazil-api.now.sh/api/report/v1",
        .event_handler = _http_event_handle,
        //.cert_pem = howsmyssl_com_root_cert_pem_start,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        ESP_LOGI(TAG, "Status = %d, content_length = %d",
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
    }
    esp_http_client_cleanup(client);
}

//Exemplo de leitura json pois não vai dar tempo 

void get_json(){
    cJSON *json = cJSON_Parse(response);

    cJSON* item;

    item = cJSON_GetObjectItemCaseSensitive(json, "temp_max");
    temp_max = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "temp");
    temp_atual = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "temp_min");
    temp_min = cJSON_GetNumberValue(item);

    cJSON_Delete(json);
    printf("Temp_Max: %lf, Temp_atual: %lf, Temp_min: %lf", temp_max, temp_atual, temp_min);
    fflush(stdout);

    vTaskDelay(1000 / portTICK_PERIOD_MS);

}