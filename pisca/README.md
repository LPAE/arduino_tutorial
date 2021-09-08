# LED

Para entender o funcionamento do arduíno podemos começar com um simples pisca LED, veremos funções básicas como PinMode e DigitalWrite, a função do PinMode vai ditar o comportamento do pino, se ele vai ser saída ou entrada. Já o digitalWrite vai dizer aos LEDs se eles vão adotar o sinal de High ou o Low (alto e baixo), ou seja, ligado e desligado.


![Esquemático buzzer passivo](./buzzer.png)

Use a função tone(pino, frequência) ou tone(pino, frequência, duração) para alterar a frequência sonora.

Veja [esse exemplo](./buzzer.ino) para gerar um alarme com frequência de 2kHz a cada 1s controlado pela serial.

Observe abaixo que o pino de acionamento é mantido em nível alto após a oscilação em 2kHz.

![Forma de onda gerado pelo código buzzer.ino](./wave.png)


## Referências

- [Documentação Arduino: Tone()](https://www.arduino.cc/reference/pt/language/functions/advanced-io/tone/)
- [Buzzer passivo 5V](https://www.filipeflop.com/produto/modulo-buzzer-5v-passivo/)


