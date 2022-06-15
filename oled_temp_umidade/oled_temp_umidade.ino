// Inclui a biblioteca do OLED
#include <U8glib.h>

//Inclui a biblioteca do sensor de temperatura e umidade
#include <DHT.h>

//Pino digital onde está conectado o sensor
#define DHT11PIN 2
//Modelo do DHT
#define DHTTYPE  DHT11

DHT dht(DHT11PIN, DHTTYPE);

// Display que não envia AC
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);


// Função setup é executada apenas uma vez
void setup(void)
{
  // Inicia a comunicação serial a 9600 bits por segundo
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

  dht.begin();
}

/* Essas variáveis são globais pois é necessário
 * manter os valores independente do contexto de
 * execução da função tarefa_1 */
const unsigned long periodo_tarefa_1 = 2000;
unsigned long tempo_tarefa_1 = millis();

float h;
float t;

void tarefa_1()
{
  unsigned long tempo_atual = millis();
  
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;

    // Lê a umidade
    h = dht.readHumidity();
    
    // Lê a temperatura em Celsius
    t = dht.readTemperature();

    // Verifica se alguma leitura falhou
    if (isnan(h) || isnan(t)) {
      Serial.println(F("Falha ao ler o sensor DHT!"));
      return;
    }
  }
}

void draw()
{
  char string[64];

  // Comandos graficos para o display devem ser colocados aqui
  // Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);

  String stringOne = String(h, 1);
  stringOne.toCharArray(string, 64);    
  
  /*Linha superior - umidade*/
  u8g.drawStr( 5, 15, string);
  u8g.drawStr( 40, 15, "% de umid.");
  
  /*Temperatura*/ 
  //Converte float para string
  stringOne = String(t, 1);
  //Converte string para char 
  stringOne.toCharArray(string, 64);    
  u8g.setFont(u8g_font_fub30);
  u8g.drawStr( 7, 57, string);
   
  // Desenho Grau C
  u8g.setFont(u8g_font_fub30);
  u8g.drawCircle(92, 30, 4);
  u8g.drawStr( 95, 57, "C");
  
  // Moldura relogio
  u8g.drawRFrame(0, 18, 128, 46, 4);
  
}

const unsigned long periodo_tarefa_2 = 1000;
unsigned long tempo_tarefa_2 = millis();

void tarefa_2(){

  unsigned long tempo_atual = millis();
  
  if(tempo_atual - tempo_tarefa_1 > periodo_tarefa_1) {
    tempo_tarefa_1 = tempo_atual;
    
    u8g.firstPage();
    do
    {
      draw();
    }while ( u8g.nextPage() );
  }
}

void loop() {
  
  tarefa_1();
  tarefa_2();
  
}
