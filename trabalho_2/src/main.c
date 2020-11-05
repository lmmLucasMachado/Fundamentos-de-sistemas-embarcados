#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "../inc/system_control.h"

int main(int argc, const char * argv[]){
    
    signal(SIGINT, interrupt_system);

    init_lib_gpio();
    
    int lamp[5], air[3], status[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    get_json(lamp, air);
    
    int sens;

    //sens = get_sens(2);
    //printf("\npino 16 e %d\n",sens);

    int i;

    while(1){
        // lamp on/off
        //printf("\nAQUI\n");
        for(i = 0;i < 4;i++){
            if (lamp[i] == 0)
                set_high_gpio(i);

            else if(lamp[i] == 1)
                set_low_gpio(i);
        }

        // air on/off
        for(i = 0;i < 2;i++){
            if (air[i] == 0)
                set_high_gpio(i + 4);
            else if(air[i] == 1)
                set_low_gpio(i + 4);
        }

    }

    return 0;

}


// thread lampadas e arcondicionado
// thread sensores presenca
// thread sensores
// thread temp/hum