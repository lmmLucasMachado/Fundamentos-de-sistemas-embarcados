
#include "../inc/interrupt_system.h"


void interrupt_system(int signal) {
    
    int i;

    extern pthread_t control_thread[2];
    // stop threads
    for(i = 0;i < 2;i++)
        pthread_cancel(control_thread[i] );

    // Close Socket
    extern int sock_fd;
    close(sock_fd);

    exit(0);

}
