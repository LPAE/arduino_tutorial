# Matriz de LED 8×8 com MAX7219

## Montagem do circuito

<img src = "matriz.png" alt = "Circuito mmatriz" width = 500 />

## Código

```C
// Inclui a biblioteca
#include <MatrizLed.h>

// Nomeando a matriz de led
MatrizLed matriz;

// Função setup é executada apenas uma vez
void setup() {
  matriz.begin(10, 8, 9, 2); // dataPin, clkPin, csPin, numero de matrizes de 8x8
  matriz.rotar(false); // Caso ocorra falha
}

// Função loop é para executar repetidamente o código
void loop() {
  matriz.borrar();
  matriz.escribirFraseScroll("Testando", 200); // Exibe o texto na matriz de led
}
```
