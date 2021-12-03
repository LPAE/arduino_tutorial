// Define a entrada analogica com o valor "1"
#define ENTRADA_ANALOGICA A1

// Recebe a leitura feita no pino analógico
int aRec;

// Função setup é executada apenas uma vez
void setup()
{
  // Inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
}

// Função loop é para executar repetidamente o código
void loop()
{
  tarefa_1();
}

/* Essas variáveis são globais pois é necessário
   manter os valores independente do contexto de
   execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();

//Envia os valores interios para o PC
void tarefa_1() {
  unsigned long tempo_atual = millis ();

  //Hora de enviar os dados caso tenha passado 1000 ms
  if (tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {

    // Faz a leitura do sensor
    aRec = analogRead(ENTRADA_ANALOGICA);

    // Envia para o computador (serial) os dados
    Serial.print("Leitura entrada analógica: ");
    Serial.println(aRec);
    Serial.println();

  }
}


// Define o pino "13" onde o relé está conectado
#define RELE 13

// Função setup é executada apenas uma vez
void setup() {

  // Configura o pino do LED como saída
  pinMode (RELE, OUTPUT);

}
// Função loop é para executar repetidamente o código
void loop()
{
  // Liga o relé
  digitalWrite(RELE, HIGH);
  // Aguarda
  delay(2000);
  // Desliga o relé
  digitalWrite(RELE, LOW);
  // Aguarda
  delay(2000);
}
