#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include "../inc/uart.h"
#include "../inc/lcd.h"
#include "../inc/bme280_temp.h"

int main(int argc, const char * argv[]){
    //signal(SIGINT, interrupt_signal);

    float temp_out = 0, temp_in = 0, potenc= 0;

    while (1){
        temp_out = get_temp_outside();
        potenc = get_potentiometer();
        temp_in = get_temp_inside();

        lcd_temperatures(temp_out,temp_in,10.0);

        printf("\n--------------------------\n");
        printf("temp externa: %.2f;\ntemp interna: %.2lf;\ntemppotenciometro %.2f\n", temp_out, temp_in, potenc);
        
    }
    
    return 0;

}
