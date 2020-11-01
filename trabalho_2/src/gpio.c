#include "../inc/gpio.h"

void init_lib_gpio(){
    bcm2835_init();
}

/*
    Lâmpada 01 (Cozinha)                    17
    Lâmpada 02 (Sala)                       18
    Lâmpada 03 (Quarto 01)                  27
    Lâmpada 04 (Quarto 02)                  22
    Ar-Condicionado 01 (Quarto 01)          23
    Ar-Condicionado 02 (Quarto 02)          24
    Sensor de Presença 01 (Sala)            25
    Sensor de Presença 02 (Cozinha)         26
    Sensor Abertura 01 (Porta Cozinha)      05
    Sensor Abertura 02 (Janela Cozinha)     06
    Sensor Abertura 03 (Porta Sala)         12
    Sensor Abertura 04 (Janela Sala)        16
    Sensor Abertura 05 (Janela Quarto 01)   20
    Sensor Abertura 06 (Janela Quarto 02)   21
*/

// LOW      on
// HIGHT    off

void set_high_gpio(int pin){

    if (!bcm2835_init())
        exit(1);

    switch (pin) {
    case 17:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_01, HIGH);
        break;
    case 18:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_02, HIGH);
        break;
    case 27:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_03, HIGH);
        break;
    case 22:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_04, HIGH);
        break;
    case 23:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AR_01, HIGH);
        break;
    case 24:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AR_02, HIGH);
        break;
    case 25:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_P_01, HIGH);
        break;
    case 26:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_P_02, HIGH);
        break;
    case 5:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_01, HIGH);
        break;
    case 6:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_02, HIGH);
        break;
    case 12:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_03, HIGH);
        break;
    case 16:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_04, HIGH);
        break;
    case 20:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_05, HIGH);
        break;
    case 21:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_06, HIGH);
        break;
    default:
        printf("Opção invalida");
        break;
    }
    
}

void set_low_gpio(int pin){

    if (!bcm2835_init())
        exit(1);

    switch (pin) {
    case 17:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_01, LOW);
        break;
    case 18:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_02, LOW);
        break;
    case 27:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_03, LOW);
        break;
    case 22:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(LAMP_04, LOW);
        break;
    case 23:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AR_01, LOW);
        break;
    case 24:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(AR_02, LOW);
        break;
    case 25:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_P_01, LOW);
        break;
    case 26:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_P_02, LOW);
        break;
    case 5:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_01, LOW);
        break;
    case 6:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_02, LOW);
        break;
    case 12:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_03, LOW);
        break;
    case 16:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_04, LOW);
        break;
    case 20:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_05, LOW);
        break;
    case 21:
        bcm2835_gpio_fsel(RESISTOR, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_write(SENS_A_06, LOW);
        break;
    default:
        printf("Opção invalida");
        break;
    }
    
}