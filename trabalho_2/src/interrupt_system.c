
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    // GPIO
    extern pthread_t control_thread;
    pthread_cancel(control_thread);

    extern int sock_fd;
    close(sock_fd);

    int i;
    for(i = 0;i < 6;i++)
        set_high_gpio(i);
 
    bcm2835_close();
    exit(0);

}
