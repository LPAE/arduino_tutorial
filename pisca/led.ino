#define LED 11  // Define o LED com o valor "11" que é onde o pino está conectado
                        
void setup() // Função setup é executada apenas uma vez
{
  pinMode (LED, OUTPUT); // Configura o pino do LED como saída
}

void loop() // Função loop é para executar repetidamente o código.
{
 digitalWrite(LED, HIGH);  // Acender LED
 delay(1000); // Aguarda 1000 milissegundos
 digitalWrite(LED,LOW); // Apagar LED
 delay(1000); // Aguarda 1000 milissegundos
 
}
