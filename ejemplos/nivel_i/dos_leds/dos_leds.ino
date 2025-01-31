/*
  Dos LEDs en un solo pin
  Martes 3 de noviembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/5dBqdBrEKS9

*/

const int LEDS = 6;

void setup() {
  pinMode(LEDS, OUTPUT);
}

void loop() {
  
  digitalWrite(LEDS, HIGH);
  delay(500);
  digitalWrite(LEDS, LOW);
  delay(500);

}