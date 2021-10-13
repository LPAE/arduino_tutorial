# Sensor de Gás e Fumaça

O sensor MQ-2 possui duas saídas: uma analógica (A0) e outra digital (D0). A função _analogRead_ pode ser utilizada para ler o valor inteiro proporcional ao gás detectado pelo sensor quanto o pino digital pode ser lido pela função _digitalRead_. O valor de gás detectado pelo sensor para a saída digital pode ser ajustado pelo _trimpot_ azul no sensor. Nesse exemplo, ambos as saídas do sensor são exibidas no no Monitor Serial. Assim que o sensor detectar a presença de um gás inflamável ou fumaça, a entrada digital vai ficar com o valor zero e os valores da entrada analógica começam a subir.

## Montagem do Circuito

<img src= "gas.png" alt = "Circuito Gas" width = "500" />

## Código

```C
// Define a entrada digital com o valor "53"
#define ENTRADA_DIGITAL 53
// Define a entrada analogica com o valor "1"
#define ENTRADA_ANALOGICA A1

// Recebe a leitura feita no pino digital
bool dSensor;
// Recebe a leitura feita no pino analógico
int aSensor;

// Função setup é executada apenas uma vez
void setup()
{
  // Configura a entrada digital como entrada
  pinMode (ENTRADA_DIGITAL, INPUT);
  // Inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}

// Função loop é para executar repetidamente o código
void loop()
{
  // Faz a leitura do sensor
  dSensor = digitalRead(ENTRADA_DIGITAL);
  aSensor = analogRead(ENTRADA_ANALOGICA);

  // Envia para o computador (serial) os dados
  Serial.print("Leitura entrada digital: ");
  Serial.println(dSensor);
  Serial.print("Leitura entrada analógica: ");
  Serial.println(aSensor);
  Serial.println();

  // Aguarda 1s
  delay(1000);
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
