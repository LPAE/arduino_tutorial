// Define o pino "11" onde o relé está conectado
#define RELE 11
// Define o pino "13" onde est´ o LED da placa
#define LED 13

// Função setup é executada apenas uma vez
void setup() {

  // Configura o pino do relé como saída
  pinMode (RELE, OUTPUT);
  // Configura o pino do LED como saída
  pinMode (LED, OUTPUT);

}

/* Essas variáveis são globais pois é necessário
 * manter os valores independente do contexto de
 * execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 2000;
unsigned long tempo_tarefa_1 = millis();

//Inicializa o  rele e o LED em LOW
int estado_RELE = LOW;
int estado_LED = LOW;

/* Tarefa que quando o rele esta em LOW passa ele para HIGH e acende 
um LED, e quando esta em HIGH vai para LOW e apaga o LED*/
void tarefa_1(){
  
  unsigned long tempo_atual = millis();
  
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;
    
    if (estado_RELE == LOW) {
      estado_RELE = HIGH;
      estado_LED = HIGH;
    } 
    else {
      estado_RELE = LOW;
      estado_LED = LOW;
    }
    
   digitalWrite(RELE, estado_RELE);
   digitalWrite(LED, estado_LED);
  }
}
  
// Função loop é para executar repetidamente o código
void loop(){

tarefa_1();

}
