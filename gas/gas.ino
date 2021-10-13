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
