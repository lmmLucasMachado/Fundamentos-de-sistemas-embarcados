# Projeto 3

Projeto 3 da Disciplina de Fundamentos de Sistemas Embarcados (2020/1)

## 1. Objetivos

Este trabalho tem por objetivo a familiarização com o framework de desenvolvimento ESP-IDF para a programação do ESP32-Dev-Kit. Mais especificamente o controle do sistema de Wifi juntamente com o acionamento da GPIO.

## 2. Componentes do Sistema

Kit de desenvolvimento ESP32-Dev-Kit e acesso a um roteador Wi-fi conectado à internet.

## 3. Requisitos

O aluno deverá criar um programa na ESP32 capaz de:
1. Conectar-se à internet no modo Station (STA) com as credenciais de Wifi sendo definidas através de variáveis de ambiente do Menuconfig.
2. Enquanto a ESP não se conecta à internet, o LED da placa deverá ficar piscando a cada 1 segundo. Assim que a conexão for estabelecida, o LED deverá permanecer aceso. Caso haja perda de conexão o mesmo deve voltar ao estado piscando.
3. Após confirmar a conexão com a internet, o sistema deverá relizar a cada 5 min uma request aos seguintes serviços:  
   1. ipstack.com para identificar a localização atual do dispositivo à partir do encereço de IP.
   2. openweathermap.org para consultar a previsão do tempo baseado na localização atual.
4. Cada vez que a ESP realiza uma request, o LED deve piscar uma vez.
5. Imprimir no console a Temperatura atual, máxima e mínima previstas para o dia e a umidade.
6. Disponibilizar o repositório com o código fonte de modo que o mesmo possa ser compilado à partir de outro computador configurado com a ESP-IDF somente à partir do comando idf.py build.

Obs: Cada um dos serviços descritos possui acesso gratuito, porém, é necessário criar contas para gerar as chaves de acesso às APIs REST. Neste caso, ambas as chaves deve ser configuradas como variáveis de ambiente do projeto.


## 4. Critérios de Avaliação

A avaliação será realizada seguindo os seguintes critérios:

|   ITEM    |   DETALHE  |   VALOR   |
|-----------|------------|:---------:|
|**Configuração do Wifi**  |   Correta configuração do Wifi. |   2,0   |
|**Configuração das variáveis de ambiente**  |   Configuração das variáveis de ambiente através do menuconfig.  |   1,0   |
|**Request HTTP** |  Correta realização da request HTTP para as APIs REST. |   1,0   |
|**Resgate da localização**   |  Correta interpretação dos dados JSON coletados à partir da API ipstack.com. |   1,0   |
|**Resgate de dados de Previsão do Tempo**   |   Correta interpretação dos dados JSON coletados à partir da API openweathermap.org.  |   1,0 |
|**Impressão dos dados de Tempo**    |   Correta impressão dos dados de tempo na tela.  |   1,0   |
|**Acionamento do LED** |   Correto acionamento do LED nos vários modos descritos.    |   1,0   |
|**Qualidade do Código** |   Utilização de boas práticas como o uso de bons nomes, modularização e organização em geral. |   2,0 |

## 5. Referências

[IP Stack](https://ipstack.com/)

[OpenWeather Map](https://home.openweathermap.org/)



