#ifndef GPIO__H
#define GPIO__H

#include <bcm2835.h>
#include <stdio.h>

// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024

#define LAMP_01 RPI_GPIO_P1_17
#define LAMP_02 RPI_GPIO_P1_18
#define LAMP_03 RPI_GPIO_P1_27
#define LAMP_04 RPI_GPIO_P1_22
#define AIR_01 RPI_GPIO_P1_23
#define AIR_02 RPI_GPIO_P1_24
/*
#define SENS_PRE_01 RPI_GPIO_P1_25
#define SENS_PRE_02 RPI_GPIO_P1_26
#define SENS_OPEN_01 RPI_GPIO_P1_05
#define SENS_OPEN_02 RPI_GPIO_P1_06
#define SENS_OPEN_03 RPI_GPIO_P1_12
#define SENS_OPEN_04 RPI_GPIO_P1_16
#define SENS_OPEN_05 RPI_GPIO_P1_20
#define SENS_OPEN_06 RPI_GPIO_P1_21
*/

void init_lib_gpio();

void set_high_gpio(int pin);

void set_low_gpio(int pin);

#endif