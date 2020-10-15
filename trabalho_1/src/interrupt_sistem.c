
#include "../inc/interrupt_sistem.h"


void interrpt_sistem(int signal) {
    // GPIO
    bcm2835_gpio_write(FAN, HIGH);
    bcm2835_gpio_write(RESISTOR, HIGH);
    
    exit(0);

}