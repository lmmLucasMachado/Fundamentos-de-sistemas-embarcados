#ifndef GPIO__H
#define GPIO__H

#include <bcm2835.h>
#include <stdio.h>

#include "../inc/system_control.h"

// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024

#define LAMP_01         17
#define LAMP_02         18
#define LAMP_03         27
#define LAMP_04         22

#define AIR_01          23
#define AIR_02          24

#define SENS_PRE_01     25
#define SENS_PRE_02     26

#define SENS_OPEN_01    05
#define SENS_OPEN_02    06
#define SENS_OPEN_03    12
#define SENS_OPEN_04    16
#define SENS_OPEN_05    20
#define SENS_OPEN_06    21


void init_lib_gpio();

void set_high_gpio(int pin);

void set_low_gpio(int pin);

#endif