#include "../inc/interrupt_system.h"

void sig_write_csv();

float temp_out = 0, temp_in = 0, temp_tr= 0;

int main(int argc, const char * argv[]){
    
    signal(SIGINT, interrupt_system);

    FILE *p_file;
    p_file = fopen ("../data.csv", "w+");
    fprintf(p_file, "\"Data\",\"Hora\",\"Temp exeterna\",\"Temp interna\",\"Temp desejada\"\n");
    fclose(p_file);

    printf("-----------------  Menu  -----------------\n");
    printf("0 - Fechar prog.\n");
    printf("1 - pegar temperatura pelo potenciometro.\n");
    printf("2 - para digitar uma temperatura.\n");
    printf("\nDigite apenas um numero e pressione enter.\n");

    int buffer = 0, gpio_high = 0, gpio_low = 0;

    //menu
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

            scanf("%f", &temp_tr);
            break;
        }
        else{
            printf("Opcao invalida, por favor escolha uma opcao listada no menu, grato.\n");
            
        }

    }while(1);

    signal(SIGALRM, sig_write_csv);
    alarm(2);

    init_lib_gpio();

    while (1){
        sleep(0.100);
        temp_out = get_temp_outside();
        temp_in = get_temp_inside();

        if (buffer == 1){
            sleep(0.100);
            temp_tr = get_potentiometer();
        }

        post_lcd_temperatures(temp_in, temp_out, temp_tr);

        // 1 RESISTOR       LOW - ON
        // 2 FAN            WIGH - OFF
        if (temp_in > temp_tr){
            gpio_high = 1;
            gpio_low = 2;
        }else if (temp_in < temp_tr){
            gpio_high = 2;
            gpio_low = 1;
        }
        else
            gpio_high = gpio_low = 0;

        set_high_gpio(gpio_high);
        set_low_gpio(gpio_low);

        printf("\n--------------------------\n");
        printf("temp externa: %.2f;\ntemp interna: %.2lf;\ntemppotenciometro %.2f\n", temp_out, temp_in,temp_tr);
        
    }
    
    return 0;

}

void sig_write_csv(){

    struct tm *date_hour;     
    time_t segundos;
    time(&segundos);   

    date_hour = localtime(&segundos);  

    FILE *p_file;
    p_file = fopen ("../data.csv", "a+");
    fprintf(p_file,"\"%d/%d/%d\",", date_hour->tm_mday, date_hour->tm_mon+1,date_hour->tm_year+1900);
    fprintf(p_file,"\"%d:%d:%d\",", date_hour->tm_hour, date_hour->tm_min, date_hour->tm_sec);
    fprintf(p_file, "\"%0.2lf\",\"%0.2lf\",\"%0.2lf\"\n", temp_out, temp_in, temp_tr);
    fclose(p_file);

    //printf("\n\nEscrevendo csv\n\n");
    alarm(2);

}
