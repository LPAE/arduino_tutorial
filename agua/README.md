# Sensor de Água
O sensor de água através de suas dez trilhas no módulo vai captar se existe a presença de água. E se detectar a leitura da entrada analógica repassara esses dados fazendo assim com que acione o LED.

## Montagem do Circuito

<img src = "agua.png" alt = "Circuito água" width = "500" />

## Código

```C
#define entradaAnalogica 0

int valorSensor   = 0;
int led   = 13 ;


void setup() {
  Serial.begin(9600);
  pinMode (led, OUTPUT);

}

void loop()

const unsigned long periodo_tarefa_1 = 1000;
unsigned long tempo_tarefa_1 = 0;
int valorSensor = analogRead (entradaAnalogica);
{
  tarefa_1();
}
valorSensor = analogRead(POT);
if (valorSensor > 300)
{
  digitalWrite(led, HIGH);
}
else {
  digitalWrite(led, LOW);
}
Serial.println(valorSensor);
}
```

