// Inclui a biblioteca
#include <MatrizLed.h>

// Nomeando a matriz de led
MatrizLed matriz;

// Função setup é executada apenas uma vez
void setup() {
  // dataPin, clkPin, csPin, numero de matrizes de 8x8
  matriz.begin(10, 8, 9, 2); 
  // Caso ocorra falha
  matriz.rotar(false); 
}


void tarefa_1() {
  matriz.borrar();
  // Exibe o texto na matriz de led
  matriz.escribirFraseScroll("Testando", 200); 
}

// Função loop é para executar repetidamente o código
void loop(){
  tarefa_1();
}
