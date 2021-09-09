# Sensor de presença PIR

Para usar o sensor de presença PIR, usaremos o digitalRead que vai receber um valor High ou Low, tendo conexão com uma porta digital, assim que essa porta digital perceber algum movimento vai informar para o arduino exibindo no monitor serial, dando um sinal de HIGH. Caso não detecte nada, enviará um sinal de LOW.

## Montagem do circuito



![Circuito LED](./LED.png)

## Código

```C
#define LED 11  // Define o LED com o valor "11" que é onde o pino está conectado
                        
void setup() // Função setup é executada apenas uma vez
{
  pinMode (LED, OUTPUT); // Configura o pino do LED como saída
}

void loop() // Função loop é para executar repetidamente o código.
{
 digitalWrite(LED, HIGH);  // Acender LED
 delay(1000); // Aguardar 1000 milissegundos
 digitalWrite(LED,LOW); // Apagar LED
 delay(1000); // Aguardar 1000 milissegundos
 
}
```
