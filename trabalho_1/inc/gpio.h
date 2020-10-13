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

void set_gpio(int pin);


#endif