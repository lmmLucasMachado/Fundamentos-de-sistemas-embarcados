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
#include "../inc/gpio.h"
void init_lib_gpio(){
    bcm2835_init();
}

void close_lib_gpio(){
    bcm2835_close();
}

void interrpt_gpio(int signal) {
    bcm2835_close();
    exit(0);
}

void set_high_gpio(int pin){

    if (!bcm2835_init())
        exit(1);
 
    //1 resistor
    //2 fan
    if (pin == 1){
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(RESISTOR, HIGH);
    }
    else if (pin == 2){
        bcm2835_gpio_fsel(FAN, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(FAN, HIGH);
    }
    else
        printf("Estavel");
    
}

void set_low_gpio(int pin){

    if (!bcm2835_init())
        exit(1);
 
    //1 resistor
    //2 fan
    if (pin == 1){
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(RESISTOR, LOW);
    }
    else if (pin == 2){
        bcm2835_gpio_fsel(FAN, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(FAN, LOW);
    }
    else
        printf("opcao invalida");
    
}