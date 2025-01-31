/*
  Entrada optoacoplada
  Lunes 5 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/83dxqgFBi6W

*/

const int OPTOAC = 2;

void setup() {
  pinMode(OPTOAC, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if (digitalRead(OPTOAC) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

}
