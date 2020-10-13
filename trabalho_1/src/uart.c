#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#include "../inc/uart.h"

float reading(char code);

float get_temp_outside(){

    float num_float = 0;

    num_float = reading(0xA2);

    return num_float;
}

float get_potentiometer(){

    float num_float = 0;

    num_float = reading(0xA1);

    return num_float;
}

float reading(char code){
    int uart0_filestream = -1;

    uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);      //Open in non blocking read/write mode
    
    if (uart0_filestream == -1){
        printf("Erro - Não foi possível iniciar a UART.\n");
        
        return 0;
    }

    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;     //<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

    char padrao[] ={code, 5, 9, 1, 7};

    int count = write(uart0_filestream, &padrao[0], 5);

    if(count < 0){
        printf("Erro - Não foi possível enviar a mensagem de solicitação para a UART.\n");
        close(uart0_filestream);
        return 0;
    }

    sleep(1);

    float num_float;

    //0xA1 potenciometro
    //0xA2 temp externo
    count = read(uart0_filestream, &num_float, 4);

    if(count < 0)
        printf("Erro na leitura.\n");
    
    else if(count == 0)
        printf("Dado indisponível.\n");
    else
        printf("%f\n", num_float);

    close(uart0_filestream);

    return num_float;
}
