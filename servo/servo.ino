// Inclui a biblioteca
#include <Servo.h>
// Pino digital onde está conectado o servo
#define SERVOPIN 3

// Nomeando o servo
Servo SRV;

// Armazena a posição do servo
int pos = 0;

// Função setup é executada apenas uma vez
void setup()
{
  //Porta onde o servo está conectado
  SRV.attach(SERVOPIN);
}

/* Essas variáveis são globais pois é necessário
 * manter os valores independente do contexto de
 * execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();

void tarefa_1(){

  unsigned long tempo_atual = millis();

  /* Hora de piscar o led caso tenha passado 1000 ms */
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {

    tempo_tarefa_1 = tempo_atual;

    if (pos == 180)
      pos = 0;
    else
      pos = 180;

    SRV.write(pos);
  }

}

// Função loop é para executar repetidamente o código
void loop(){
  tarefa_1();
}
