#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "../inc/lcd.h"
#include "../inc/lcd_lib.h"

void post_lcd_temperatures(float temp_in, float temp_out, float temp_re){

    if (wiringPiSetup () == -1) exit (1);

    fd = wiringPiI2CSetup(I2C_ADDR);

    lcd_init(); // setup LCD

    printf("Temperature out: %f\n", temp_out);
    printf("Temperature inside %f\n", temp_in);


    char line1[255];
    sprintf(line1, "TI:%0.2f T2:%0.2f", temp_in, temp_out);

    char line2[255];
//    sprintf(line2, "TR: %0.2f ", temp_re);
    sprintf(line2, "deu certo ");

    printf(line1);
    printf(line2);

    ClrLcd();
    lcdLoc(LINE1);
    typeln(line1);
    lcdLoc(LINE2);
    typeln(line2);

    printf("\n--------------------------------------\n\nLCD\nTI:%0.2f T2:%0.2f\n", temp_in, temp_out);

}
