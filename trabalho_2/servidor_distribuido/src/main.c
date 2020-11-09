#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

pthread_t control_thread[2];

int main(int argc, const char * argv[]){

    signal(SIGINT, interrupt_system);
    // send data
    signal(SIGALRM, server_write);
    alarm(1);

    init_lib_gpio();

    init_server_listen();

    pthread_create (&control_thread[0], NULL, listen_server, NULL);
    pthread_create (&control_thread[1], NULL, init_maintain_data, NULL);
    printf("\naqui\n");
    
    pthread_join(control_thread[0], NULL);
    pthread_join(control_thread[1], NULL);

    //printf("fim");
    return 0;
}
