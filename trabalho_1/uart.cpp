#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string>

#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;
int main(int argc, char const *argv[])
{
    // Setup
    int uart0_filestream = -1;
    string a = "/dev/serial0";
    unsigned int mat = 0x9503;

    uart0_filestream = open(a.c_str(), O_RDWR | O_NOCTTY);
    if (uart0_filestream == -1)
    {
        cerr << "Error: Serial port not working" << endl;
        return -1;
    }

    // Config UART
    struct termios options;
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

    if (uart0_filestream == -1)
    {
        cerr << "Error: Serial port not working" << endl;
        return -1;
    }

    unsigned char uart_buffer[256] = {0};
    // 0xa1 integer
    // 0xa2 float
    /*
        Trabalho 01 
        a1 potenciometro
        a0 medidor da temperatura
    */
    unsigned char buffer[] = {0xa2,5,9,1,7};
    
    int count = write(uart0_filestream, &buffer, 5);
    cout << "Escrevendo" << endl;
    debug(count);
    if (count <= 0)
    {
        cerr << "Error: Dont write in uart comunication" << endl;
    }

    count = 0;
    // usleep(200);
    // char buffer_u[256];
    float buffer_u = 0;
    cout << "Lendo" << endl;

    count = read(uart0_filestream, &buffer_u, 4);
    debug(count);
    debug(buffer_u);
    if (count < 0)
    {
        cerr << "Error: Dont read in uart comunication" << endl;
    }
    else if (count == 0)
    {
        cerr << "Device not find" << endl;
    }
    else
    {
        cout << "The uart answer is " << uart_buffer << endl;
    }

    close(uart0_filestream);
    return 0;   
}