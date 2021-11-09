//Inclui a biblioteca
#include <DHT.h>

//Pino analógico onde está conectado o sensor
#define DHT11PIN A1
//Modelo do DHT
#define DHTTYPE  DHT11

DHT dht(DHT11PIN, DHTTYPE);

// Função setup é executada apenas uma vez
void setup() {
  // inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  dht.begin();
}

// Função loop é para executar repetidamente o código
void loop()
{
  tarefa_1();
}

/* Essas variáveis são globais pois é necessário
   manter os valores independente do contexto de
   execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 2000;
unsigned long tempo_tarefa_1 = millis();

//Envia os valores interios para o PC
void tarefa_1() {
  unsigned long tempo_atual = millis ();

  //Hora de enviar os dados caso tenha passado 2000 ms
  if (tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {

    // Lê a umidade
    float h = dht.readHumidity();
    // Lê a temperatura em Celsius
    float t = dht.readTemperature();
    // Lê a temperatura como Fahrenheit
    float f = dht.readTemperature(true);

    // Verifica se alguma leitura falhou
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Falha ao ler o sensor DHT!"));
      return;
    }
    // Envia para o computador (serial) os dados
    Serial.print(F("Umidade: "));
    Serial.print(h);
    Serial.print(F("%  Temperatura: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.println(F("°F"));
  }
}
