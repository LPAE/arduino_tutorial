# Sensor de Umidade e Temperatura

## Montagem do Circuito

<img src= ".png" alt = "Circuito umidade" width = "500" />

## Código
```C
#include <DHT.h>

#define DHT11pin A1
#define DHTTYPE  DHT11

DHT dht(DHT11pin, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
 
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
```

## Resultados

Humidity: 71.00%  Temperature: 28.70°C 83.66°F  Heat index: 32.25°C 90.06°F
Humidity: 71.00%  Temperature: 28.60°C 83.48°F  Heat index: 32.04°C 89.67°F
Humidity: 72.00%  Temperature: 28.50°C 83.30°F  Heat index: 31.99°C 89.58°F
Humidity: 72.00%  Temperature: 28.50°C 83.30°F  Heat index: 31.99°C 89.58°F
Humidity: 72.00%  Temperature: 28.40°C 83.12°F  Heat index: 31.77°C 89.19°F
Humidity: 72.00%  Temperature: 28.30°C 82.94°F  Heat index: 31.56°C 88.81°F
Humidity: 73.00%  Temperature: 28.30°C 82.94°F  Heat index: 31.71°C 89.08°F
Humidity: 73.00%  Temperature: 28.30°C 82.94°F  Heat index: 31.71°C 89.08°F
Humidity: 73.00%  Temperature: 28.20°C 82.76°F  Heat index: 31.50°C 88.70°F


