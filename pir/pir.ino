// Define o PIR com o valor "7" que é onde o pino digital está conectado
#define pinPIR 7

// Função setup é executada apenas uma vez
void setup() 
{
  // Configura o pino como entrada
  pinMode (pinPIR, INPUT);
  // inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}

// Função loop é para executar repetidamente o código
void tarefa_1()
{
  // Se houver movimento
  if (digitalRead(pinPIR) == HIGH) {
    // Enviar para monitor serial
    Serial.println("Presenca detectada");
  } else {
    // Se não houver movimento enviar para monitor serial
    Serial.println("-----");
  }
}

void loop(){
  
  tarefa_1();
  
}
