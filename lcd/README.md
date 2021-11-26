# Display LCD 16×2 I2C 

O nosso display LCD possui o módulo I2c que facilita na hora de fazer as conexões nas portas do arduino, mesmo assim precisamos ter atenção na hora de conectar ele, pois em alguns arduinos não vem escrito na placa qual é a entrada SDA e SCL.  Para utilizá-lo, vamos precisar de uma biblioteca específica. 

## Montagem do circuito

<img src = "lcd.png" alt = "Circuito lcd" width = 500 />          

## Código

```C
// Inclui a biblioteca
#include <Wire.h>
// Inclui a biblioteca
#include <LiquidCrystal_I2C.h>

// Define o endereço LCD para 0x27 para um display de 16 caracteres e 2 linhas
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Função setup é executada apenas uma vez
void setup()
{
  // inicializa o LCD
  lcd.init();
  //liga a luz de fundo
  lcd.backlight();
  // Posição do cursor
  lcd.setCursor(1, 0);
  // Imprime uma mensagem no LCD
  lcd.print("Ola");
  // Posição do cursor
  lcd.setCursor(1, 1);
  // Imprime uma mensagem no LCD
  lcd.print("Testando");
}


void loop()
{
}
```
