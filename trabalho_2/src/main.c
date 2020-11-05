#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include<json-c/json.h>

//#include "../inc/gpio.h"

void *lamp();

int main(int argc, const char * argv[]){
    
    pthread_t thread_lamp;
    void * thread_res;
    int status_lamp;

    status_lamp = pthread_create(&thread_lamp, NULL, lamp, NULL);



    return 0;

}

void *lamp() {

    init_lib_gpio();

    
    pthread_exit(NULL);
}

// thread lampadas
// thread sensores presenca
// thread arcondicionado
// thread sensores
// thread temp/hum