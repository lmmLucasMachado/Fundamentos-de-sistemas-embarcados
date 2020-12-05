#ifndef SYSTEM_CONTROL__H
#define SYSTEM_CONTROL__H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <signal.h>


#include "./cJSON.h"
#include "./gpio.h"
#include "./bme280_i2c.h"
#include "./interrupt_system.h"

#define SA struct sockaddr 
#define MAX_MSG 1024

#define PORT_D 10105
#define PORT_C 10005

#define SERVIDOR_DISTRIBUIDO "192.168.0.52"
#define SERVIDOR_CENTRAL "192.168.0.53"

void init_server_listen();

void get_json();

int status_sensor();

void init_maintain_data();

void maintain_data_csv();

void server_listen(void *args);

void server_write();

#endif