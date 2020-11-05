#ifndef SYSTEM_CONTROL__H
#define SYSTEM_CONTROL__H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "../inc/cJSON.h"
#include "../inc/gpio.h"
#include "../inc/bme280_i2c.h"
#include "../inc/interrupt_system.h"

#define MAX_MSG 1024

void get_json(int* lamp, int* air);

void status_sensor(int *status);

#endif