#include "../inc/gpio.h"



void init_lib_gpio(){
    bcm2835_init();
/*
    // init lamp
    bcm2835_gpio_fsel(LAMP_01, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(LAMP_02, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(LAMP_03, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(LAMP_04, BCM2835_GPIO_FSEL_OUTP);
    
    // init air
    bcm2835_gpio_fsel(AIR_01, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(AIR_02, BCM2835_GPIO_FSEL_OUTP);
    
    bcm2835_gpio_fsel(SENS_PRE_01, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_PRE_02, BCM2835_GPIO_FSEL_OUTP);
    
    bcm2835_gpio_fsel(SENS_OPEN_01, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_OPEN_02, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_OPEN_03, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_OPEN_04, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_OPEN_05, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(SENS_OPEN_06, BCM2835_GPIO_FSEL_OUTP);
*/

}

/*
    Lâmpada 01 (Cozinha)                    0
    Lâmpada 02 (Sala)                       1
    Lâmpada 03 (Quarto 01)                  2
    Lâmpada 04 (Quarto 02)                  3
    Ar-Condicionado 01 (Quarto 01)          4
    Ar-Condicionado 02 (Quarto 02)          5
    Sensor de Presença 01 (Sala)            6
    Sensor de Presença 02 (Cozinha)         7
    Sensor Abertura 01 (Porta Cozinha)      8
    Sensor Abertura 02 (Janela Cozinha)     9
    Sensor Abertura 03 (Porta Sala)         10
    Sensor Abertura 04 (Janela Sala)        11
    Sensor Abertura 05 (Janela Quarto 01)   12
    Sensor Abertura 06 (Janela Quarto 02)   13
*/

// LOW      on
// HIGHT    off

void set_high_gpio(int pin){

    if (!bcm2835_init())
        exit(1);

    switch (pin) {
    case 0:
        bcm2835_gpio_fsel(LAMP_01, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_01, HIGH);
        break;
    case 1:
        bcm2835_gpio_fsel(LAMP_02, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_02, HIGH);
        break;
    case 2:
        bcm2835_gpio_fsel(LAMP_03, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_03, HIGH);
        break;
    case 3:
        bcm2835_gpio_fsel(LAMP_04, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_04, HIGH);
        break;
    case 4:
        bcm2835_gpio_fsel(AIR_01, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AIR_01, HIGH);
        break;
    case 5:
        bcm2835_gpio_fsel(AIR_02, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AIR_02, HIGH);
        break;
/*
    case 6:
        bcm2835_gpio_write(SENS_PRE_01, HIGH);
        break;
    case 7:
        bcm2835_gpio_write(SENS_PRE_02, HIGH);
        break;
    case 8:
        bcm2835_gpio_write(SENS_OPEN_01, HIGH);
        break;
    case 9:
        bcm2835_gpio_write(SENS_OPEN_02, HIGH);
        break;
    case 10:
        bcm2835_gpio_write(SENS_OPEN_03, HIGH);
        break;
    case 11:
        bcm2835_gpio_write(SENS_OPEN_04, HIGH);
        break;
    case 12:
        bcm2835_gpio_write(SENS_OPEN_05, HIGH);
        break;
    case 13:
        bcm2835_gpio_write(SENS_OPEN_06, HIGH);
        break;
*/
    default:
        printf("Opcao invalida");
        break;
    }
    
}

void set_low_gpio(int pin){

    if (!bcm2835_init())
        exit(1);

    switch (pin) {
    case 0:
        bcm2835_gpio_fsel(LAMP_01, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_01, LOW);
        break;
    case 1:
        bcm2835_gpio_fsel(LAMP_02, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_02, LOW);
        break;
    case 2:
        bcm2835_gpio_fsel(LAMP_03, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_03, LOW);
        break;
    case 3:
        bcm2835_gpio_fsel(LAMP_04, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_04, LOW);
        break;
    case 4:
        bcm2835_gpio_fsel(AIR_01, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AIR_01, LOW);
        break;
    case 5:
        bcm2835_gpio_fsel(AIR_02, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AIR_02, LOW);
        break;
/*
    case 6:
        bcm2835_gpio_write(SENS_PRE_01, LOW);
        break;
    case 7:
        bcm2835_gpio_write(SENS_PRE_02, LOW);
        break;
    case 8:
        bcm2835_gpio_write(SENS_OPEN_01, LOW);
        break;
    case 9:
        bcm2835_gpio_write(SENS_OPEN_02, LOW);
        break;
    case 10:
        bcm2835_gpio_write(SENS_OPEN_03, LOW);
        break;
    case 11:
        bcm2835_gpio_write(SENS_OPEN_04, LOW);
        break;
    case 12:
        bcm2835_gpio_write(SENS_OPEN_05, LOW);
        break;
    case 13:
        bcm2835_gpio_write(SENS_OPEN_06, LOW);
        break;
*/
    default:
        printf("Opcao invalida");
        break;
    }
    
}