#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

int main(int argc, const char * argv[]){

    pthread_t control_thread;
    
    signal(SIGINT, interrupt_system);

    init_lib_gpio();

    int sens;

    sens = get_sensor(0);
    printf("\npino 16 e %d\n",sens);

    
        pthread_create (&control_thread, NULL, set_gpio, NULL);
        pthread_join(control_thread, NULL);

    

    return 0;

}


// thread lampadas e arcondicionado
// thread sensores presenca
// thread sensores
// thread temp/hum