// Inclui a biblioteca
#include <U8glib.h>

// Display que não envia AC
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

// Função draw é executada apenas uma vez
void draw()
{
  // Comandos graficos para o display devem ser colocados aqui
  // Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);
  // Linha superior - temperatura
  u8g.drawStr( 5, 15, "23");
  u8g.drawCircle(28, 8, 3);
  u8g.drawStr( 34, 15, "C");
  // Hora
  u8g.setFont(u8g_font_fub30);
  u8g.drawStr( 10, 57, "09:35");
  // Texto - AM
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr( 115, 33, "AM");
  // Moldura relogio
  u8g.drawRFrame(0, 18, 128, 46, 4);
  // Desenho bateria
  u8g.drawRFrame(105, 3, 20, 12 , 0);
  u8g.drawBox(125, 6, 2, 6);
  u8g.drawBox(107, 5, 4, 8);
  u8g.drawBox(114, 5, 4, 8);
  // Desenho linhas sinal
  u8g.drawVLine(99, 0, 15);
  u8g.drawVLine(98, 0, 15);
  u8g.drawVLine(96, 4, 11);
  u8g.drawVLine(95, 4, 11);
  u8g.drawVLine(93, 8, 7);
  u8g.drawVLine(92, 8, 7);
  u8g.drawVLine(90, 12, 3);
  u8g.drawVLine(89, 12, 3);
}

// Função setup é executada apenas uma vez
void setup(void)
{
  // inicia a comunicação serial a 9600 bits por segundo
  Serial.begin(9600);
  // Cor Branca
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);
  }
  // Intensidade máxima
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);
  }
  // Pixel ligado
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255, 255, 255);
  }
}

// Função loop é para executar repetidamente o código
void loop(void)
{
  u8g.firstPage();
  do
  {
    draw();
  } while ( u8g.nextPage() );
  // Aguarda 50 ms
  delay(50);
}
