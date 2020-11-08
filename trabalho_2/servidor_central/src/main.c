#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

pthread_t control_thread[2];

int main(int argc, const char * argv[]){
        
    signal(SIGINT, interrupt_system);

    init_server();

    pthread_create (&control_thread[0], NULL, server_listen, NULL);
    pthread_join(control_thread[0], NULL);

    pthread_create (&control_thread[1], NULL, server_write, NULL);
    pthread_join(control_thread[1], NULL);

    return 0;

}
