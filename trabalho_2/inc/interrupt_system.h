#ifndef INTERRUPT_SYSTEM__H
#define INTERRUPT_SYSTEM__H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include <signal.h>
#include "../inc/gpio.h"
#include "../inc/bme280_i2c.h"


void interrupt_system(int signal);

#endif