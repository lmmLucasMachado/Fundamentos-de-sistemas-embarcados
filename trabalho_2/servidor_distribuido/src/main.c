#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

pthread_t control_thread[3];

int main(int argc, const char * argv[]){

    signal(SIGINT, interrupt_system);

    init_lib_gpio();

    init_server();

    pthread_create (&control_thread[0], NULL, listen_server, NULL);
    pthread_join(control_thread[0], NULL);

    pthread_create (&control_thread[1], NULL, init_maintain_data, NULL);
    pthread_join(control_thread[1], NULL);

    pthread_create (&control_thread[2], NULL, write_server, NULL);
    pthread_join(control_thread[2], NULL);

    return 0;
}
