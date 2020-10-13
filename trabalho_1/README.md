# Projeto 1

Projeto 1 da disciplina de Fundamentos de Sistemas Embarcados

## 1. Objetivos

Este trabalho tem por objetivo a realização do controle de temperatura de um sistema. O sistema possui internamente dois dispositivos para alterar sua temperatura. O primeiro é um resistor de potência de 15 Watts utilziado para aumentar temperatura e o segundo, uma ventoinha que puxa o ar externo (à temperatura ambiente) para reduzir a temperatura. 

A temperatura de referência (TR) pode ser definida pelo usuário do sistema de duas maneiras:
1. Através de um Potenciômetro;
2. Através de entrada de teclado no terminal.

O controle de temperatura do sistema deve ser realizado utilizando a abordagem de controle On/Off com histerese. A histerese é definida como a diferença entre o limite superior e o inferior da variável a ser controlada. Por exemplo, se a temperatura de operação do sistema for definida como 40˚C com histerese de 4˚C, os limites inferior e superior serão respectivamente de 38˚C e 42˚C.

Neste caso, quando o valor medido de temperatura ficar abaixo do limite inferior, o controlador deverá acionar o resistor de potência para aquecer o sistema. Caso a temperatura medida esteja acima do limite superior, o controlador deve desligar a resistência e acionar a ventoinha. 

## 2. Componentes do Sistema

O sistema como um todo é composto por:
1. Ambiente fechado controlado com o resistor de potência e ventoinha;
2. 01 Sensor LM35 para a medição da temperatura interna (TI) do ambiente fechado;
3. 01 Sensor BME280 (I2C) para a medição da temperatura externa (TE);
4. 01 módulo Display LCD 16x2 com circuito I2C integrado (Controlador HD44780);
5. 01 Conversor lógico bidirecional (3.3V / 5V);
6. Circuito de potência com 2 relés;
6. 01 Arduino Micro;
7. Potenciômetro;
8. Raspberry Pi 4;

![Figura](./img/Figura_Trabalho_1.png)

## 3. Conexões entre os módulos do sistema

1. O sensor de temperatura BM280 está ligado ao barramento I2C e utiliza o endereço (0x76);
2. O módulo de display LCD está conectado ao barramento I2C utilizando o endereço 0x27;
3. O resistor de potência e a ventoinha estão ambos ligados às portas GPIO e são acionados através do circuito de potência com relés;
    3.1. Resistor: GPIO 23 ou Pino 16 (Board)
    3.2. Ventoinha: GPIO 24 ou Pino 18 (Board)
    3.3. Atenção: o acionamento dos relés está invertido. Portanto o valor de GPIO como 1 desliga o equipamento enquanto 0 liga (Sugestão: usar a bibliteca bcm2835).
4. O Arduino está conectado à placa Raspberry Pi via UART;
5. O potenciômetro é conectado à porta analógica (A1) do Arduino;
6. O sensor de temperatura LM35 para medição do ambiente controlado está ligado à porta analógica (A2) do Arduino;

## 4. Requisitos

Os sistema de controle possui os seguintes requisitos:
1. O código deve ser desenvolvido em C/C++;
2. O sistema deve implementar o controle de temperatura On/Off do ambiente fechado;
3. O sistema deve apresentar uma interface de controle via terminal com menu de interação com o usuário e dados de temperaturas (TI, TE, TR) sendo atualizados a cada 500 ms;
4. O usuário deve ser capaz de escolher se quer definir a temperatura do  através de entrada de teclado ou pelo potenciômetro;
5. No caso da temperatura ser definida pelo potenciômetro, o programa deve consultar o valor do potenciômetro através da comunicação UART com o Arduino a cada ~~100 ms~~ -> 500 ms;
6. O sistema deve apresentar na tela LCD os valores das temperaturas (TI, TE, TR);
7. O programa deve gerar um log em arquivo CSV das seguintes informações a cada 02 segundos (Data e hora, temperatura interna, temperatura externa, temperatura definida pelo usuário).
8. O valor de histerese deve poder ser definido pelo usuário;
9. O código deve possuir Makefile para compilação;

## 5. Comunicação UART com Arduino

A leitura do valor do potenciômetro deve seguir o mesmo protocolo utilizado no [Exercício 1](referencias/Exercicio_1_UART.pdf). 
O Arduino fornece duas informações para o sistema, valor da temperatura interna (Sensor LM35) e valor da temperatura de referência (Potenciômetro).

Para acessar as informações via UART envie mensagens no seguinte formato:
1. Temperatura interna: 0xA1 + 4 últimos dígitos da matrícula. O retorno será o valor em Float (4 bytes) da temperatura interna do sistema;
2. Temperatura de referência (Potenciômetro): 0xA2 + 4 últimos dígitos da matrícula. O retorno será o valor em Float (4 bytes) da temperatura de referência definida pelo usuário;

## 6. Critérios de Avaliação

A avaliação será realizada seguindo os seguintes critérios:

|   ITEM    |   COMENTÁRIO  |   VALOR   |
|------------------------|---------------------------------------------------------------------------------------------------------|---------|
|**Implementação do controlador** | Correta implementação do controlador On/Off com histerese, incluindo a leitura das temperaturas e acionamento dos atuadores (resistor e ventoinha. |    3,0 |
|**Menu de controle**        | Correta implementação do menu com as opções de acesso do usuário e sua atualização de informações. | 1,0 |
|**Leitura do Potenciômetro**| Leitura do potenciômetro através da comunicação UART com o Arduino. | 1,5 |
|**Mostrador no LCD**        | Apresentação das 3 temperatudas no LCD. | 1,5 |
|**Armazenamento em arquivo**| Armazenamento em arquivo CSV dos dados medidos. |   1,0 |
|**Qualidade do Código**     | Utilização de boas práticas como o uso de bons nomes, modularização e organização em geral.    |  2,0 |
|**Pontuação Extra**         |   Qualidade e usabilidade acima da média.  |  0,5   |

## 7. Referências

[Driver da Bosh para o sensor BME280](https://github.com/BoschSensortec/BME280_driver)

[Biblioteca BCM2835 - GPIO](http://www.airspayce.com/mikem/bcm2835/)

[Controle do LCD 16x2 em C](http://www.bristolwatch.com/rpi/i2clcd.htm)




