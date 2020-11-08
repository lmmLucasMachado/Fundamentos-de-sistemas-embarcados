
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    
    int i;

    extern pthread_t control_thread[3];
    // stop threads
    for(i = 0;i < 3;i++)
        pthread_cancel(control_thread[i] );

    // Close Socket
    extern int sock_fd;
    close(sock_fd);

    // Off GPIO
    for(i = 0;i < 6;i++)
        set_high_gpio(i);
    
    //close GPIO
    bcm2835_close();
    exit(0);

}
