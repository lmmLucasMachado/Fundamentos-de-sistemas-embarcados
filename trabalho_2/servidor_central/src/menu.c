#include "../inc/menu.h"

void menu(){

    int buffer = 0, alarm, lamp;
    double temp_wish;
    //menu
    do{

        printf("-----------------  Menu  -----------------\n");
        printf("0 - Fechar programa.\n");
        printf("1 - Acionar lampadas ou arcondicionado.\n");
        printf("2 - Escolher temperatura do ambiente.\n");
        printf("3 - Acionar sensor.\n");
        printf("\nDigite apenas um numero e pressione enter.\n");
        
        scanf("%d", &buffer);

        if (buffer == 0){
            printf("Opcao escolhida \"0\", fechar programa.\nObrigado. \n");

            break;
        }else if (buffer == 1){
            printf("Opcao escolhida \"1\", acionar lampadas ou arcondicionado.\n");
            printf("Escolha qual lampada quer acionar.\n");

            printf("0 - Fechar programa.\n");
            printf("1 - Lampada da cozinha.\n");
            printf("2 - Lampada da sala.\n");
            printf("3 - Lampada da quarto 1.\n");
            printf("4 - Lampada da quarto 2.\n");

            scanf("%d", &lamp);

            // acionar lamp
        }else if(buffer == 2){
            printf("Opcao escolhida \"2\", escolher temperatura do ambiente.\nDigite a temperatura desejada.\n");

            scanf("%lf", &temp_wish);
            
            //mandar temperatura
        }else if(buffer == 3){
            printf("Opcao escolhida \"3\", acionar alarme.\nEscolha qual alarm quer disparar.\n");

            printf("0 - Fechar programa.\n");
            printf("1 - Para acionar o alarme.\n");

            scanf("%f", &alarm);

            // acionar alarm
        }
        else{
            printf("Opcao invalida, por favor escolha uma opcao listada no menu, grato.\n");
        }

        if (buffer == 0)
            break;

    }while(1);
}

void status_disp(){
    
}