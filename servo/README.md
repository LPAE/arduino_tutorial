# Micro Servo SG92R 9g TowerPro

O micro servo possui um motor capaz de direcionar ele para um ângulo específico. O servo que vamos utilizar tem o seu ângulo de rotação máxima de 180°, e pode ser controlado de forma muito precisa com o Arduino.

## Montagem do circuito

<img src = "servo.png" alt = "Circuito servo" width = 400 />          

## Código

```C
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

// Função loop é para executar repetidamente o código
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
```
