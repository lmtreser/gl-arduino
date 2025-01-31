/*
  Control de cargas mediante relé
  30 de septiembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/bfQhHkgatJl

*/

const int RELE = 2, TIEMPO = 1500;

void setup() {

  pinMode(RELE, OUTPUT);

}

void loop() {

  digitalWrite(RELE, HIGH);
  delay(TIEMPO);
  digitalWrite(RELE, LOW);
  delay(TIEMPO);

}
