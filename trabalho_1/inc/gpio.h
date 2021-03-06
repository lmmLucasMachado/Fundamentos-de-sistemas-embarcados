#ifndef GPIO__H
#define GPIO__H

// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define RESISTOR RPI_GPIO_P1_16
#define FAN RPI_GPIO_P1_18
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024

// pwm.c
//
// Example program for bcm2835 library
// Shows how to use PWM to control GPIO pins
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o pwm pwm.c -l bcm2835 
// sudo ./pwm
//
// Or you can test it before installing with:
// gcc -o pwm -I ../../src ../../src/bcm2835.c pwm.c
// sudo ./pwm
//
// Connect an LED between GPIO18 (pin 12) and GND to observe the LED changing in brightness
//
// Author: Mike McCauley
// Copyright (C) 2013 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
 
#include <bcm2835.h>
#include <stdio.h>

void init_lib_gpio();

//void interrpt_gpio(int signal);

void set_high_gpio(int pin);

void set_low_gpio(int pin);

#endif