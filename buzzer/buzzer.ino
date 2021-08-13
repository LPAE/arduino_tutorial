
/*
   buzzer.ino

    Criado em: 13 de agosto de 2021
        Renan Augusto Starke
        Instituto Federal de Santa Catarina

        Aplicação exemplo com duas tarefas:
          - Acionar um Buzzer formando um alarme de 1 segundo ligado e 1 segundo desligado.
          - Buzzer/alarme é acionado se recebido 'a' pela serial.

                 Arduino Uno/Mega
                 -----------------
             /|\|                 |
              | |                 |
              --| RST             |
                |                 |        -+
    BUZZER <--  | D8              |- <- Rx  -  Cabo USB
                |                 |- -> Tx  -
                |                 |        -+
                |                 | 

*/

#define PINO_BUZZER 8


/* Função SETUP é executa apenas uma vez
   ela é responsável pela configuração dos
   pinos do Arduino */
void setup() {

  /* Comunicação serial com o computador */
  Serial.begin(9600);
  while (!Serial);

  /* Configuração dos pinos como entrada ou saída */
  pinMode(PINO_BUZZER, OUTPUT);

  /* Mantém buzzer desligado se acionamento for PNP
     Troque para HIGH para LOW caso NPN
  */
  digitalWrite(PINO_BUZZER, HIGH);
}

/* Essas variáveis são globais pois é necessário
   manter os valores indenpendente do contexto de
   execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = 0;
int estado_alarme = LOW;
bool ligar_alarme = false;

/* Tarefa 1: pisca o LED a cada 1 segundo */
void tarefa_1() {

  unsigned long tempo_atual = millis();

  /* Hora de executa essa tarefa */
  if (tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {

    tempo_tarefa_1 = tempo_atual;

    if (ligar_alarme == true) {

      if (estado_alarme == HIGH) {
        estado_alarme = LOW;
        tone(PINO_BUZZER, 2000);
      }
      else {
        estado_alarme = HIGH;

        /* Depende do Buzzer:

           Se acionado com NPN, use apenas noTone(PINO_BUZZER);

           Se acionado com PNP, use abaixo para deixar o pino em nível alto.

            noTone(PINO_BUZZER);
            digitalWrite(PINO_BUZZER, HIGH);

        */
        noTone(PINO_BUZZER);
        digitalWrite(PINO_BUZZER, HIGH);
      }

    }
    else {
      noTone(PINO_BUZZER);
      digitalWrite(PINO_BUZZER, HIGH);
    }
  }

}

/* Tarefa 2: gerencia os comandos da porta serial */
void tarefa_2() {

  /* Caso tenha recebido algum dado do PC */
  if (Serial.available()) {
    char dado_recebido = Serial.read();

    /* Depuração */
    Serial.print("Recebido:");
    Serial.println("a");

    if (dado_recebido == 'a')
      if (ligar_alarme == true)
        ligar_alarme = false;
      else
        ligar_alarme = true;

  }
}

/* Função loop() é responsável por escalonar as tarefas.
   Essa função é executada eternamete (enquanto o Arduino estiver
   energizado) */
void loop() {

  tarefa_1();

  tarefa_2();
}

