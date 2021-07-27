# Dicas para projetos no Arduino

O Arduino Uno não é um microcontrolador muito poderoso e isso está relacionado diretamente ao poder de computacional global. Contudo, a velocidade de execução ainda é bastante alta para lidar com a maioria dos sistemas físicos que se deseja controlar.

Lembre-se que o microcontrolador ATmega328p que equipa as placas do Arduino Uno utiliza um clock de 16MHz.

Com o objetivo de executar várias __"tarefas"__ no Arduino, siga as seguintes dicas:

- Não use a função delay(). Esta função bloqueia completamente o seu sistema.  Existem outras maneiras de obter o mesmo comportamento da função delay() como será exemplificado abaixo.

- Minimize o tempo de execução de todas as suas funções. Um baixo tempo de execução não significa que suas funções devam ter no máximo x linhas de código, mas você deve monitorar o tempo de execução e certificar-se de que é relativamente baixo.

- Nunca bloqueie o sistema esperando por algum evento externo. Se o seu programa está esperando uma entrada do usuário, por exemplo, uma mensagem de texto de comunicação serial, você não controla quando esse evento vai acontecer. Bloquear é a maneira mais fácil de obter os dados usuário, porém essa técnica pode ter um efeito pior que o uso da função delay(). Existem outras maneiras de manter a comunicação externa sem bloquear como será exemplificado abaixo.

- Use algo como uma máquina de estado para processos muito longos. Exemplificando, caso você tenha um processo que realmente requer muitas ações diferentes e um certo tempo de espera entre essas duas ações, é melhor você separar esse processo em várias pequenas funções e criar uma máquina de estado em seu programa principal para chamá-los um por um, quando necessário. Isso permite que você execute outras parte do programa entre essas duas etapas sequencias do processo.


## Exemplo

Considere o seguinte hardware:

- 4 LEDs conectados em 4 pinos digitais pins (saídas).
- 1 botão conectado a 1 pino digital (entrada).
- 1 potenciômetro conectado a uma entrada anaĺógica.
- Cabo USB conectado no computador.

![Hardware](https://roboticsbackend.com/wp-content/uploads/2019/01/arduino_schematics_leds_button_potentiometer.jpg)


Requisitos da aplicação:

- Piscas o LED 1 a cada 1 segundo.
- Ler um valor entre 0 a 255 do usuário pela porta Serial (USB) e escrever o valor no LED 2.
- Ligar o LED 3 se o botão é pressionado.
- Ligar o LED 4 se o valor analógico do potenciômetro for maior que 312.
- Enviar o valor do potenciômetro a cada 2 segundos.  

## Código

\```c:./tarefas/tarefas.ino

\```

## Referências

- [Guia de funções do Arduino](https://www.arduino.cc/reference/pt/)

- [Multitasking with Arduino](https://roboticsbackend.com/how-to-do-multitasking-with-arduino/)

- [Multitasking using loops](https://www.codeproject.com/Articles/1271587/Arduino-Multitasking-Using-Loops)

- [Datasheet ATmega328p](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

- [Carro autônomo em Arduino](https://github.com/xtarke/automated_buggy/tree/master/arduino)
