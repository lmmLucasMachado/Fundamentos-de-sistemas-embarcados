#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

pthread_t control_thread;

int main(int argc, const char * argv[]){
        
    signal(SIGINT, interrupt_system);
    
    init_server();
    
    init_maintain_data();
    
    //signal(SIGALRM, server_write);
    //alarm(1);

    pthread_create (&control_thread, NULL, server_listen, NULL);
    pthread_join(control_thread, NULL);

    return 0;

}
