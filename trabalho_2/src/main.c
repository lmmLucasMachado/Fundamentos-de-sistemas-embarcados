#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include<json-c/json.h>

#include "../inc/interrupt_system.h"

void *set_lamp_and_air();

int main(int argc, const char * argv[]){
    
    signal(SIGINT, interrupt_system);

    pthread_t thread_lamp_and_air;
    void * thread_res;
    int status_lamp_and_air;

    status_lamp_and_air = pthread_create(&thread_lamp_and_air, NULL, set_lamp_and_air, NULL);

    return 0;

}

void *set_lamp_and_air() {

    init_lib_gpio();
    int lamp[5], air[3];

    get_json(lamp, air);

    int i;
    
    // lamp on/off
    for(i = 0;i > 4;i++){
        if (lamp[i] == 0)
            set_high_gpio(i);
        else if(lamp[i] == 1)
            set_low_gpio(i)
    }

    // air on/off
    for(i = 0;i > 2;i++){
        if (air[i] == 0)
            set_high_gpio(i + 4);
        else if(air[i] == 1)
            set_low_gpio(i + 4)
    }
    
    
    pthread_exit(NULL);
}

// thread lampadas e arcondicionado
// thread sensores presenca
// thread sensores
// thread temp/hum