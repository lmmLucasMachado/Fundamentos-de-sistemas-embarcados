
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    // GPIO
    bcm2835_gpio_write(FAN, HIGH);
    bcm2835_gpio_write(RESISTOR, HIGH);
    
    exit(0);

}
