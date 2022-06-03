# Sensor de Água

Esse sensor detecta a presença ou nível de água de forma analógica pela alteração da resistência das trilhas paralelas presentes na superfície da placa de circuito impresso. No exemplo a seguir, caso o valor analógico lido seja maior que 300 o LED irá se acender, assim, indicando a presença de água. O valor da atuação e calibração deve ser ajustado para cada aplicação.

## Montagem do Circuito

<img src = "agua.png" alt = "Circuito água" width = "500" />

## Código

```C
// Define a entrada analógica 0 conectada ao sensor
#define PINO_SENSOR_AGUA A0
// Define o pino "13" onde o LED está conectado
#define LED 13

// Função setup é executada apenas uma vez
void setup() {
  // inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
  // Configura o pino do LED como saída
  pinMode (LED, OUTPUT);

}

/* Essas variáveis são globais pois é necessário
   manter os valores independente do contexto de
   execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();

/* Tarefa 1: envia o valor analógico para o PC */
void tarefa_1() {

  int valorSensor;

  /* Hora de enviar os dados analógicos caso tenha passado 1000 ms */
  if (tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;

    valorSensor = analogRead(PINO_SENSOR_AGUA);

    Serial.print("Valor : ");
    Serial.println(valorSensor);

    //Acender o LED de acordo com o valor da entrada analógica
    if (valorSensor > 300)
      digitalWrite(LED, HIGH);
    else
      digitalWrite(LED, LOW);

  }
}

/* Função loop() é responsável por escalonar as tarefas.
   Essa função é executada eternamente enquanto o Arduino estiver energizado */
void loop() {

  unsigned long tempo_atual = millis();

  tarefa_1();

}
```
## Vídeo do funcionamento 
- [Sensor de água](https://youtu.be/0SRkrS9IWHs)
