# Sensor de presença PIR

Para usar o sensor de presença PIR, usaremos o digitalRead que vai receber um valor High ou Low, tendo conexão com uma porta digital, assim que essa porta digital perceber algum movimento vai informar para o Arduino exibindo no monitor serial, dando um sinal de HIGH. Caso não detecte nada, enviará um sinal de LOW.

## Montagem do circuito

<img src="pir.png" alt="Circuito PIR" width="500"/>

## Código

```C
// Define o PIR com o valor "7" que é onde o pino digital está conectado
#define pinPIR 7

// Função setup é executada apenas uma vez
void setup() /
{
  // Configura o pino como entrada
  pinMode (pinPIR, INPUT);
  // inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}

// Função loop é para executar repetidamente o código
void loop()
{
  // Se houver movimento
  if (digitalRead(pinPIR) == HIGH) {
    // Enviar para monitor serial
    Serial.println("Presença detectada");
  } else {
    // Se não houver movimento enviar para monitor serial
    Serial.println("-----");
  }
}
```
## Referências

- [Datasheet do sensor](https://siccciber.com.br/wp-content/uploads/2020/06/FTC-PIR.pdf)


