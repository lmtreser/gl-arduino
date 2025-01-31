/*
  BLINK
  El ejemplo más básico de todos
  Domingo 13 de septiembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/gz2XZsnJDrz

*/

const int TIEMPO = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  delay(TIEMPO); //Demora de 500 milisegundos
  digitalWrite(LED_BUILTIN, LOW);
  delay(TIEMPO); //Demora de 500 milisegundos
  
}
