# Sensor de Umidade do solo

## Montagem do Circuito

## Código
```C
// Define a entrada digital com o valor "52"
#define ENTRADA_DIGITAL 52
// Define a entrada analogica com o valor "1"
#define ENTRADA_ANALOGICA A1

// Função setup é executada apenas uma vez
void setup() {
  // Configura a entrada digital como entrada
  pinMode(ENTRADA_DIGITAL, INPUT);
  // Inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}

// Função loop é para executar repetidamente o código
void loop() {
  Serial.print("Digital:");

  if (digitalRead(ENTRADA_DIGITAL)) {
    Serial.print("SEM UMIDADE ");
  } else {
    Serial.print("COM UMIDADE ");
  }
  Serial.print("  Analogico:");
  Serial.print(analogRead(ENTRADA_ANALOGICA));
  Serial.print("  ");

}
```

## Resultados 
Leitura entrada digital: 1
Leitura entrada analógica: 765

Leitura entrada digital: 1
Leitura entrada analógica: 718

Leitura entrada digital: 1
Leitura entrada analógica: 601

Leitura entrada digital: 0
Leitura entrada analógica: 509

Leitura entrada digital: 0
Leitura entrada analógica: 445

Leitura entrada digital: 0
Leitura entrada analógica: 378
