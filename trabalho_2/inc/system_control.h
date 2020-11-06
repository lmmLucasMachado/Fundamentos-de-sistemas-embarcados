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


#include "../inc/cJSON.h"
#include "../inc/gpio.h"
#include "../inc/bme280_i2c.h"
#include "../inc/interrupt_system.h"

#define SA struct sockaddr 
#define MAX_MSG 1024
#define PORT_D 10105
#define PORT_C 10005

void init_server();

void get_json(int* lamp, int* air);

void status_sensor(int *status);

void *set_gpio(void* args);

#endif