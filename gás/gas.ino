#define entradaDigital 53 // Define a entrada digital com o valor "53"
#define entradaAnalogica 1  // Define a entrada analogica com o valor "1"

bool dSensor; // Recebe a leitura feita no pino digital
int aSensor; // Recebe a leitura feita no pino analógico

void setup() // Função setup é executada apenas uma vez
{
  pinMode (entradaDigital, INPUT); // Configura a entrada digital como entrada
  Serial.begin(9600);  // inicia a comunicação serial a 9600 bits por segundo
}

void loop() // Função loop é para executar repetidamente o código
{

  dSensor = digitalRead(entradaDigital);
  aSensor = analogRead(entradaAnalogica);
  
  Serial.print("Leitura entrada digital: ");
    Serial.println(dSensor);
  Serial.print("Leitura entrada analógica: ");
    Serial.println(aSensor);
    Serial.println();

    delay(1000);
}
