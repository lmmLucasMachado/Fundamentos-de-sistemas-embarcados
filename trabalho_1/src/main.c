#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include "../inc/uart.h"
#include "../inc/lcd.h"
#include "../inc/bme280_temp.h"
#include "../inc/gpio.h"


int main(int argc, const char * argv[]){
    //signal(SIGINT, interrupt_signal);

    float temp_out = 0, temp_in = 0, temp_tr= 0, temp_wish = 0;

    int buffer = 0, gpio = 0;

    printf("-----------------  Menu  -----------------\n");
    printf("0 - Fechar prog.\n");
    printf("1 - pegar temperatura pelo potenciometro.\n");
    printf("2 - para digitar uma temperatura.\n");
    printf("\nDigite apenas um numero e pressione enter.\n");

    do{

        scanf("%d", &buffer);

        if (buffer == 0){
            printf("Opcao escolhida \"0\", fechar programa.\nObrigado. \n");

            return 0;
        }else if (buffer == 1){
            printf("Opcao escolhida \"1\", pegar temperatura pelo potenciometroa.\n");
            
            break;
        }else if(buffer == 2){
            printf("Opcao escolhida \"2\", digitar uma temperatura.\nDigite a temperatura desejada.\n");

            scanf("%f", &temp_wish);
            temp_tr = temp_wish;

            break;
        }
        else{
            printf("Opcao invalida, por favor escolha uma opcao listada no menu, grato.\n");
            
        }
    }while(1);

    int count = 0;
    while (1){
        sleep(1);
        temp_out = get_temp_outside();

        sleep(1);
        temp_in = get_temp_inside();

        if (buffer == 1){
            sleep(1);
            temp_tr = get_potentiometer();
        }

        post_lcd_temperatures(temp_out, temp_in, temp_tr);

        if (temp_in < temp_tr)
            gpio = 1;
        else if (temp_in > temp_tr)
            gpio = 2;
        set_gpio(gpio);

        printf("\n--------------------------\n");
        printf("temp externa: %.2f;\ntemp interna: %.2lf;\ntemppotenciometro %.2f\n", temp_out, temp_in,temp_tr);
        
        printf("\n%d\n",count);
        count++;
    }
    
    return 0;

}
