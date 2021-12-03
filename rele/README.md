# Módulo Relé 1 Canal 5V

O módulo relé vai funcionar como um controlador para circuitos externos com correntes maiores do que o Arduino é capaz de fornecer, porém no nosso exemplo vamos apenas acender um LED para demostrar sua funcionalidade.

## Montagem do Circuito

<img src = "rele.png" alt = "Circuito rele" width = "500" />

## Código

```C
// Define o pino "13" onde o relé está conectado
#define RELE 13

// Função setup é executada apenas uma vez
void setup() {

  // Configura o pino do relé como saída
  pinMode (RELE, OUTPUT);

}

// Função loop é para executar repetidamente o código
void loop()
{
  // Liga o relé
  digitalWrite(RELE, HIGH);
  // Aguarda 2000 ms
  delay(2000);
  // Desliga o relé
  digitalWrite(RELE, LOW);
  // Aguarda 2000 ms
  delay(2000);
}
```
