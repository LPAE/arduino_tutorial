# Sensor de Gás e Fumaça

No sensor MQ-2 vamos utilizar a função analogRead que vai informar variáveis de valores inteiros que serão repassadas para o Monitor Serial. Assim que o sensor detectar a presença de um gás inflamável ou fumaça, a entrada digital vai ficar com o valor zero e os valores da entrada analógica começam a subir. 


## Montagem do Circuito

<img src= "Gas.png" alt = "Circuito Gas" width = "500" />

## Código

```C
#define entradaDigital 53 // Define a entrada digital com o valor "53"
#define entradaAnalogica 1  // Define a entrada analogica com o valor "1"

bool dSensor; // Recebe a leitura feita no pino digital
int aSensor; // Recebe a leitura feita no pino analógico

void setup() // Função setup é executada apenas uma vez
{
  pinMode (entradaDigital, INPUT); // Configura a entrada digital como entrada
  Serial.begin(9600);  // inicia a comunicação serial a 9600 bits por segundo
}

void loop() // Função loop é para executar repetidamente o código
{

  dSensor = digitalRead(entradaDigital); // Define que a entrada digital será "dSensor"
  aSensor = analogRead(entradaAnalogica); // Define que a entrada analógica será "aSensor"
  
  Serial.print("Leitura entrada digital: "); // Lê a entrada digital
    Serial.println(dSensor); // Exibe no monitor 
  Serial.print("Leitura entrada analógica: "); // Lê a entrada analógica
    Serial.println(aSensor); // Exibe no monitor
    Serial.println();

    delay(1000); // Aguarda 1000 millisegundo
}
```

## Resultados

Leitura entrada digital: 1
Leitura entrada analógica: 24

Leitura entrada digital: 0
Leitura entrada analógica: 766

Leitura entrada digital: 0
Leitura entrada analógica: 918


## Referências

- [Sensor de Gás](https://www.masterwalkershop.com.br/sensor-detector-de-gas-inflamavel-fumaca-mq-2)
