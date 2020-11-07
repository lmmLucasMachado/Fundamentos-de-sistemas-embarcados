#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

int main(int argc, const char * argv[]){

    pthread_t control_thread[2];
    
    signal(SIGINT, interrupt_system);

    init_lib_gpio();

    init_server();

    pthread_create (&control_thread[0], NULL, server_listen, NULL);
    pthread_join(control_thread[0], NULL);

    pthread_create (&control_thread[1], NULL, init_maintain_data, NULL);
    pthread_join(control_thread[1], NULL);

    return 0;

}
