#include <string.h>
#include <stdlib.h>
#include "esp_event.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_system.h"

#include "http_client.h"
#include "./cJSON.h"

#define TAG "HTTP"
#define MAX_MSG 5000

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
            if (!esp_http_client_is_chunked_response(evt->client)) {
                printf("%.*s", evt->data_len, (char*)evt->data);
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
    }
    return ESP_OK;
}

void http_request(){
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
double temp_atual, temp_maxima, temp_minima, humidity;

void get_json(){
    char buffer[MAX_MSG];
    cJSON *json = cJSON_Parse(buffer);

    cJSON* item;

    item = cJSON_GetObjectItemCaseSensitive(json, "temp");
    temp_atual = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "temp_max");
    temp_maxima = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "temp_min");
    temp_minima = cJSON_GetNumberValue(item);

    item = cJSON_GetObjectItemCaseSensitive(json, "humidity");
    humidity = cJSON_GetNumberValue(item);

    cJSON_Delete(json);

}