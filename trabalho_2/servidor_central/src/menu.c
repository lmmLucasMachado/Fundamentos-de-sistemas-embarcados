#include "../inc/menu.h"

void menu(){
    int buffer = 0, lamp;
    double temp_wish;
    //menu
    do{
        status_disp();

        printf("-----------------  Menu  -----------------\n");
        printf("0 - Fechar programa.\n");
        printf("1 - Acionar lampadas ou arcondicionado.\n");
        printf("2 - Escolher temperatura do ambiente.\n");
        printf("3 - Acionar alarme.\n");
        printf("\nDigite apenas um numero e pressione enter.\n");
        
        scanf("%d", &buffer);

        if (buffer == 0){
            printf("Opcao escolhida \"0\", fechar programa.\nObrigado. \n");

            break;
        }else if (buffer == 1){
            do{
                printf("Opcao escolhida \"1\", acionar lampadas ou arcondicionado.\n");
                printf("Escolha qual lampada quer acionar.\n");

                printf("0 - Fechar programa.\n");
                printf("1 - Lampada da cozinha.\n");
                printf("2 - Lampada da sala.\n");
                printf("3 - Lampada da quarto 1.\n");
                printf("4 - Lampada da quarto 2.\n");
                printf("5 - Ar-condicionado 1.\n");
                printf("6 - Ar-condicionado 2.\n");

                scanf("%d", &lamp);

                if (lamp < 0 && lamp > 6)
                    printf("Opcao invalida por favor escolha um numero entre 0 e 6.\n");
                else{
                    set_disp_wish(lamp);
                    break;
                }
            }while(1);
            
            switch (lamp) {
                case 1:
                    printf(" Lampada da cozinha escolhida.\n");
                    break;
                case 2:
                    printf(" Lampada da sala escolhida.\n");
                    break;            
                case 3:
                    printf(" Lampada do quarto 1 escolhida.\n");
                    break;
                case 4:
                    printf(" Lampada do quarto 2 escolhida.\n");
                    break;            
                case 5:
                    printf(" Ar-condicionado 1 escolhido.\n");
                    break;            
                case 6:
                    printf(" Ar-condicionado 2 escolhido.\n");
                    break;            
                default:
                    break;
            }

        // acionar lamp
        }else if(buffer == 2){
            printf("Opcao escolhida \"2\", escolher temperatura do ambiente.\nDigite a temperatura desejada.\n");

            scanf("%lf", &temp_wish);
            
            set_temp_wish(temp_wish);

        //mandar temperatura
        }else if(buffer == 3){
            printf("Opcao escolhida \"3\", acionar alarme.\nEscolha qual alarm quer disparar.\n");

            // acionar alarm
            set_alarm(1);
        }
        else{
            printf("Opcao invalida, por favor escolha uma opcao listada no menu, grato.\n");
        }

        status_disp();

        if (buffer == 0)
            break;

    }while(1);
}

void status_disp(){
    int *lamp, *air;
    int alarm_;
    double temp, hum;
    
    lamp = get_lamp();
    air = get_air();

    alarm_ = get_alarm();
    temp = get_temp();
    hum = get_hum();

    printf("-----------------  Status dispositivos  -----------------\n");
    printf("\n               0 = on             1 = off\n");
    printf("Lampada cozinha:   %d          Lampada sala: %d\n", lamp[0], lamp[1]);
    printf("Lampada quarto 1:  %d          Lampada quarto 2: %d\n", lamp[2], lamp[3]);
    printf("Ar-condicionado 1: %d          Ar-condicionado 2: %d\n", air[0], air[1]);
    printf("Temperatura:       %0.2lf      Umidade: %0.2lf\n", temp, hum);
    
    if (alarm_ == 0)
        printf("\nAlarme ligado!!!\n");
    else 
        printf("\nAlarme Desligado!\n");
        
}

