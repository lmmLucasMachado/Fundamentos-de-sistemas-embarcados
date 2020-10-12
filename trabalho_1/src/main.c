#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include "../inc/uart.h"
#include "../inc/bme280_temp.h"

int main(int argc, const char * argv[]){
    //signal(SIGINT, interrupt_signal);

    float temp_out = 0, temp_in = 0, potenc= 0;

    temp_out = temp_outside();
    potenc = potenciometro();
    temp_in = return_temp_inside();

    printf("temp externa: %f;\ntemp interna: %lf;\ntemppotenciometro %f\n", temp_out,temp_in, potenc);

    return 0;

}
