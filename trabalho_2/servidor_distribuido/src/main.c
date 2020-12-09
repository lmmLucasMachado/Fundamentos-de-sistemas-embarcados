#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

pthread_t control_thread;

int main(int argc, const char * argv[]){

    signal(SIGINT, interrupt_system);

    init_lib_gpio();

    init_server_listen();

    init_maintain_data();

    // Send data
    
    signal(SIGALRM, server_write);
    alarm(1);

    // Receive data
    pthread_create(&control_thread, NULL, server_listen, NULL);
    printf("\naqui\n");
    
    pthread_join(control_thread, NULL);

    //printf("fim");
    return 0;
}
