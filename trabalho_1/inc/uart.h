#ifndef UART__H
#define UART__H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

float reading(char code);

float get_temp_outside();

float get_potentiometer();
void interrupt_uart();

#endif