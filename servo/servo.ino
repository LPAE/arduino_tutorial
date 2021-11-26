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

void loop()
{
  // 0 graus a 180 graus
  for (pos = 0; pos <= 180; pos += 1) {
    // Troca de posição
    SRV.write(pos);
    // Aguarda 15 ms
    delay(15);
  }
  // 180 graus a 0 graus
  for (pos = 180; pos >= 0; pos -= 1) {
    // Troca de posição
    SRV.write(pos);
    // Aguarda 15 ms
    delay(15);
  }
}
