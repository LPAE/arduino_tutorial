// Define o LED com o valor "11" que é onde o pino está conectado
#define LED 11

// Função setup é executada apenas uma vez
void setup()
{
  // Configura o pino do LED como saída
  pinMode (LED, OUTPUT);
}

// Função loop é para executar repetidamente o código
void loop()
{
  // Acender LED
  digitalWrite(LED, HIGH);
  // Aguarda 1000 milissegundos
  delay(1000);
  // Apagar LED
  digitalWrite(LED,LOW);
  // Aguarda 1000 milissegundos
  delay(1000); 
}
