
//Pinos de conexão dos sensores/atuadores
#define PINO_SENSOR_AGUA A0
#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode (LED, OUTPUT);

}

/* Essas variáveis são globais pois é necessário
 * manter os valores indenpendente do contexto de
 * execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();

/* Tarefa 1: envia o valor analógico para o PC */
void tarefa_1(){
  unsigned long tempo_atual = millis();

  int valorSensor;

  /* Hora de enviar os dados analógicos caso tenha passado 1000 ms */
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;

    valorSensor = analogRead(PINO_SENSOR_AGUA);

    Serial.print("Valor : ");
    Serial.println(valorSensor);

    if (valorSensor > 300)    
      digitalWrite(LED, HIGH);    
    else
      digitalWrite(LED, LOW);
   
  }
}


/* Função loop() é responsável por escalonar as tarefas.
 * Essa função é executada eternamete enquanto o Arduino estiver
 * energizado */
void loop() {

  tarefa_1();
 
}
