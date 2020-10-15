#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include "../inc/lcd.h"
#include "../inc/gpio.h"
#include "../inc/uart.h"
#include "../inc/bme280_temp.h"
#include "../inc/interrupt_sistem.h"


int main(int argc, const char * argv[]){
    
    signal(SIGINT, interrpt_sistem);

    FILE *p_file;
    p_file = fopen ("../data.csv", "w+");
    fprintf(p_file, "\"Temp exeterna\",\"Temp interna\",\"Temp desejada\"\n");
    fclose(p_file);

    //signal(SIGINT, interrupt_signal);

    float temp_out = 0, temp_in = 0, temp_tr= 0, temp_wish = 0;

    printf("-----------------  Menu  -----------------\n");
    printf("0 - Fechar prog.\n");
    printf("1 - pegar temperatura pelo potenciometro.\n");
    printf("2 - para digitar uma temperatura.\n");
    printf("\nDigite apenas um numero e pressione enter.\n");

    int buffer = 0, gpio_high = 0, gpio_low = 0, count = 0;

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

    init_lib_gpio();

    while (1){
        sleep(0.100);
        temp_out = get_temp_outside();

        sleep(0.100);
        temp_in = get_temp_inside();

        if (buffer == 1){
            sleep(0.100);
            temp_tr = get_potentiometer();
        }

        if (count == 2 ){
            p_file = fopen ("../data.csv", "a+");
            fprintf(p_file, "\"%0.2lf\",\"%0.2lf\",\"%0.2lf\"\n", temp_out, temp_in, temp_tr);
            fclose(p_file);
            count = 0;
        }

        post_lcd_temperatures(temp_in, temp_out, temp_tr);

        // 1 RESISTOR
        // 2 FAN
        // LOW - ON
        // WIGH - OFF
        if (temp_in > temp_tr){
            gpio_high = 1;
            gpio_low = 2;
        }
        else if (temp_in < temp_tr){
            gpio_high = 2;
            gpio_low = 1;
        }
        else
            gpio_high = gpio_low = 0;

        set_high_gpio(gpio_high);
        set_low_gpio(gpio_low);

        printf("\n--------------------------\n");
        printf("temp externa: %.2f;\ntemp interna: %.2lf;\ntemppotenciometro %.2f\n", temp_out, temp_in,temp_tr);
        
        count++;
    }
    
    return 0;

}
