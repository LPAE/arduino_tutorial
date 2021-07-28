# Dicas para projetos no Arduino

O Arduino Uno não é um microcontrolador muito poderoso e isso está relacionado diretamente ao poder de computacional global. Contudo, a velocidade de execução ainda é bastante alta para lidar com a maioria dos sistemas físicos que se deseja controlar.

Lembre-se que o microcontrolador ATmega328p que equipa as placas do Arduino Uno utiliza um clock de 16MHz.

Com o objetivo de executar várias __"tarefas"__ no Arduino, siga as seguintes dicas:

- Não use a função delay(). Esta função bloqueia completamente o seu sistema.  Existem outras maneiras de obter o mesmo comportamento da função delay() como será exemplificado abaixo.

- Minimize o tempo de execução de todas as suas funções. Um baixo tempo de execução não significa que suas funções devam ter no máximo x linhas de código, mas você deve monitorar o tempo de execução e certificar-se de que é relativamente baixo.

- Nunca bloqueie o sistema esperando por algum evento externo. Se o seu programa está esperando uma entrada do usuário, por exemplo, uma mensagem de texto de comunicação serial, você não controla quando esse evento vai acontecer. Bloquear é a maneira mais fácil de obter os dados usuário, porém essa técnica pode ter um efeito pior que o uso da função delay(). Existem outras maneiras de manter a comunicação externa sem bloquear como será exemplificado abaixo.

- Use algo como uma máquina de estado para processos muito longos. Exemplificando, caso você tenha um processo que realmente requer muitas ações diferentes e um certo tempo de espera entre essas duas ações, é melhor você separar esse processo em várias pequenas funções e criar uma máquina de estado em seu programa principal para chamá-los um por um, quando necessário. Isso permite que você execute outras parte do programa entre essas duas etapas sequencias do processo.


## Exemplo

Considere o seguinte hardware:

- 4 LEDs conectados em 4 pinos digitais pins (saídas).
- 1 botão conectado a 1 pino digital (entrada).
- 1 potenciômetro conectado a uma entrada anaĺógica.
- Cabo USB conectado no computador.

![Hardware](https://roboticsbackend.com/wp-content/uploads/2019/01/arduino_schematics_leds_button_potentiometer.jpg)


Requisitos da aplicação:

- Piscas o LED 1 a cada 1 segundo.
- Ler um valor entre 0 a 255 do usuário pela porta Serial (USB) e escrever o valor no LED 2.
- Ligar o LED 3 se o botão é pressionado.
- Ligar o LED 4 se o valor analógico do potenciômetro for maior que 312.
- Enviar o valor do potenciômetro a cada 2 segundos.  

## Código

```c++
/*
 * tarefas.ino
 *
 *  Criado em: 27 de julho d 2021
 *      Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 *
 *      Aplicação exemplo com várias tarefas:
 *        - Piscar o LED 1 a cada 1 segundo.
 *        - Ler um valor entre 0 a 255 do usuário pela porta Serial (USB) e escrever o valor no LED 2.
 *        - Ligar o LED 3 se o botão é pressionado.
 *        - Ligar o LED 4 se o valor analógico do potenciômetro for maior que 312.
 *        - Enviar o valor do potenciômetro a cada 2 segundos.  
 *
 *                  Arduino Uno
 *               -----------------
 *           /|\|              A0 |- <-- Potenciômetro
 *            | |                 |
 *            --| RST             |-
 *              |                 |        -+
 *  LED1  <---  | D9              |- <- Rx  -  Cabo USB
 *  LED2  <---  | D10             |- -> Tx  -
 *  LED3  <---  | D11             |        -+
 *  LED4  <---  | D12          D5 |- <- Botão
 *
*/

#define LED_1 9
#define LED_2 13
#define LED_3 11
#define LED_4 12
#define POT   A0
#define BOTAO 5


/* Função SETUP é executa apenas uma vez
 * ela é responsável pela configuração dos
 * pinos do Arduino */
void setup() {

  /* Comunicação serial com o computador */
  Serial.begin(9600);
  while (!Serial);

  /* Configuração dos pinos como entrada ou saída */
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(BOTAO, INPUT);
}

/* Essas variáveis são globais pois é necessário
 * manter os valores indenpendente do contexto de
 * execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();
int estado_LED1 = LOW;

/* Tarefa 1: pisca o LED a cada 1 segundo */
void tarefa_1(unsigned long tempo_atual){

  /* Hora de piscar o led caso tenha passado 1000 ms */
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {

    tempo_tarefa_1 = tempo_atual;

    if (estado_LED1 == HIGH)
      estado_LED1 = LOW;
    else
      estado_LED1 = HIGH;

    digitalWrite(LED_1, estado_LED1);
  }
}

/* Tarefa 2: escreve no LED2 os valor recebido pelo PC */
void tarefa_2(){

  /* Caso tenha recebido algum dado do PC */
  if (Serial.available()) {
    int dados_recebidos = Serial.parseInt();

    if (dados_recebidos >= 0 && dados_recebidos < 256) {
      analogWrite(LED_2, dados_recebidos);
    }
  }
}

/* Tarefa 3: acende o LED conforme o estado do botão */
void tarefa_3(){

 if (digitalRead(BOTAO) == HIGH)
    digitalWrite(LED_3, HIGH);
 else
    digitalWrite(LED_3, LOW);
}


/* Valor analógico é global pois ele é lido pela tarefa 5 */
int valor_analogico = 0;

/* Tarefa 4: acende o LED 4 de acordo com o valor da entrada analógica */
void tarefa_4(){

  valor_analogico = analogRead(POT);

  if (valor_analogico > 512)
    digitalWrite(LED_4, HIGH);
  else {
    digitalWrite(LED_4, LOW);
  }
}

/* Essas variáveis são globais pois é necessário
 * manter os valores indenpendente do contexto de
 * execução da função tarefa_5 */
const unsigned long periodo_tarefa_5 = 2000;
unsigned long tempo_tarefa_5 = millis();

/* Tarefa 5: envia o valor analógico para o PC */
void tarefa_5(unsigned long tempo_atual){

  /* Hora de enviar os dados analógicos caso tenha passado 2000 ms */
  if(tempo_atual - tempo_tarefa_5 > periodo_tarefa_5) {
    tempo_tarefa_5 = tempo_atual;

    Serial.print("Valor : ");
    Serial.println(valor_analogico);
  }
}  

/* Função loop() é responsável por escalonar as tarefas.
 * Essa função é executada eternamente (enquanto o Arduino estiver
 * energizado) */
void loop() {

  unsigned long meu_tempo_atual = millis();

  tarefa_1(meu_tempo_atual);

  tarefa_2();

  tarefa_3();

  tarefa_4();

  tarefa_5(meu_tempo_atual);
}

```

## Referências

- [Guia de funções do Arduino](https://www.arduino.cc/reference/pt/)

- [Multitasking with Arduino](https://roboticsbackend.com/how-to-do-multitasking-with-arduino/)

- [Multitasking using loops](https://www.codeproject.com/Articles/1271587/Arduino-Multitasking-Using-Loops)

- [Datasheet ATmega328p](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

- [Carro autônomo em Arduino](https://github.com/xtarke/automated_buggy/tree/master/arduino)
