# LED

Para entender o funcionamento do arduino podemos começar com um simples pisca LEDs, veremos funções básicas como PinMode e DigitalWrite, a função do PinMode vai ditar o comportamento do pino, se ele vai ser saída ou entrada. Já o digitalWrite vai dizer aos LEDs se eles vão adotar o sinal de High ou o Low (alto e baixo), ou seja, ligado e desligado.

## Montagem do circuito

Para utilizar o LED no arduino utilizaremos resistores para que a tensão e corrente sejam reguladas e os componentes não sofram danos. O resistor utilizado nesse exemplo é de 330 ohms, podendo ser admitidos outros valores e LEDs diferentes.

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
