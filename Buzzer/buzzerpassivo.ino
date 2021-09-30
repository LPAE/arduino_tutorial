int buzzerPin = 3;
const int frequencia = 659;
const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = millis();


void setup() {
  pinMode(buzzerPin, OUTPUT); 
  digitalWrite(buzzerPin, HIGH); 
}

void loop() {
pinMode(buzzerPin,OUTPUT);
tone(buzzerPin, frequencia);
}
void tarefa_1(unsigned long tempo_atual){
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;
}
noTone(buzzerPin);
digitalWrite(buzzerPin, HIGH);
}
