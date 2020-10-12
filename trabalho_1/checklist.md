# Checklist

1. [Consegui]O sensor de temperatura BM280 está ligado ao barramento I2C e utiliza o endereço (0x76);
2. O módulo de display LCD está conectado ao barramento I2C utilizando o endereço 0x27;
3. O resistor de potência e a ventoinha estão ambos ligados às portas GPIO e são acionados através do circuito de potência com relés;
    3.1. Resistor: GPIO 23 ou Pino 16 (Board)
    3.2. Ventoinha: GPIO 24 ou Pino 18 (Board)
    3.3. Atenção: o acionamento dos relés está invertido. Portanto o valor de GPIO como 1 desliga o equipamento enquanto 0 liga (Sugestão: usar a bibliteca bcm2835).
4. O Arduino está conectado à placa Raspberry Pi via UART;
5. [Consegui]O potenciômetro é conectado à porta analógica (A1) do Arduino;
6. [Consegui] O sensor de temperatura LM35 para medição do ambiente controlado está ligado à porta analógica (A0) do Arduino;
