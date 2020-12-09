
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    
    int i;

    extern pthread_t control_thread;
    // stop threads
    
    pthread_cancel(control_thread);

    // Close Socket
    extern int sock_fd;
    close(sock_fd);

    extern int send_socket;
    close(send_socket);

    // Off GPIO
    for(i = 0;i < 6;i++)
        set_low_gpio(i);
    
    //close GPIO
    bcm2835_close();
    exit(0);

}