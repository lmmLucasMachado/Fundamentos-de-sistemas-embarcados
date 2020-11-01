
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    // GPIO
    bcm2835_close();
    
    exit(0);

}
