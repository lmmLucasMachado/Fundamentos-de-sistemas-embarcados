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

#include "../inc/cJSON.h"
#include "../inc/interrupt_system.h"
#include "../inc/menu.h"

#define SA struct sockaddr 
#define MAX_MSG 1024

#define PORT_D 10105
#define PORT_C 10005

#define SERVIDOR_DISTRIBUIDO "192.168.0.52"
#define SERVIDOR_CENTRAL "192.168.0.53"

void init_server();

void get_json();

double get_temp();

double get_hum();

int get_alarm();

int *get_lamp();

int *get_air();

void set_temp_wish(double temp_w);

int control_air();

void set_disp_wish(int disp_w);

void set_alarm(int alarm_w);

void server_listen();

void server_write();

#endif
