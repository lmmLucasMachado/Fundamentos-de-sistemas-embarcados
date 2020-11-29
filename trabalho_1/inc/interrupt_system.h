#ifndef INTERRUPT_SYSTEM__H
#define INTERRUPT_SYSTEM__H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include <signal.h>
#include "../inc/lcd.h"
#include "../inc/gpio.h"
#include "../inc/uart.h"
#include "../inc/bme280_temp.h"
#include "../inc/control.h"


void interrupt_system(int signal);

#endif