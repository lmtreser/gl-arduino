/*
  Tonos
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
   https://www.tinkercad.com/things/87k5AZ4bnI9

*/

const int BUZZER = 9;

void setup() {
  
  pinMode(BUZZER, OUTPUT);

}

void loop() {

  // pin, frecuencia
  tone(BUZZER, 900);
  delay(400);
  tone(BUZZER, 300);
  delay(400);

}
