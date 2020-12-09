# Trabalho 02 - da disciplina de sistema embarcados

Para ver o problema a que se refere este trabalho basta ir na pasta enenunciado em readme, la constam todas as informações para que se possa entender o escopo deste projeto e as referencias usadas para consolidalo.

## Executar

Para executar é necessário ir em cada uma das pastas do servidor e executar os comandos abaixo:

```
make clean
```

```
make
```

```
make run
```

Aluno: Lucas Machado
 
Matricula: 15/0015917

|Status|   ITEM    |   DETALHE  |   VALOR   |
|-------|-----------|------------|:---------:|
||**Servidor Central**    |       |       |
|Parcialmente|**Comunicação TCP/IP**  |   Correta implementação de comunicação entre os servidores usando o protocolo TCP/IP. |   2,0   |
|Feito|**Interface com o estado**  |   Interface (linha de comando) apresentando o estado de cada dispositivo, a temperatura e a umidade.  |   1,0   |
|Feito|**Interface (Acionamento)** |   Mecanismo para acionamento de dispositivos, definição de temperatura do Ar. |   1,0   |
|Feito|**Acionamento do Alarme**   |   Mecanismo de ligar/desligar alarme e acionamento do alarme de acordo com o estado dos sensores. |   1,0   |
|Feito|**Log (CSV)**   |   Geração de Log em arquivo CSV.  |   0,5 |
| ---- |**Servidor Distribuído**    |       |       |
|Feito|**Leitura de Temperatura / Umidade**    |   Leitura e armazenamento dos valores de temperatura / umidade a cada 1 segundo.  |   1,0   |
|Feito|**Acionamento de Dispositivos** |   Correto acionamento de lâmpadas e aparelhos de ar-condicionado pelo comando do Servidor Central.    |   1,0   |
|-----|**Estado dos Sensores** |   Enviar como mensagem (Push) para o Servidor Central um alerta pelo acionamento dos sensores de presença / abertura de portas/janelas.   |   1,0  |
|Feito|**Qualidade do Código** |   Utilização de boas práticas como o uso de bons nomes, modularização e organização em geral. |   1,5 |
||**Pontuação Extra** |   Qualidade e usabilidade acima da média. |   1,0   |
