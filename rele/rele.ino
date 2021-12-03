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
