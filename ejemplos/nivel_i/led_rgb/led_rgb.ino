/*
  LED RGB (cátodo común)
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/7Hj3VY9amNm

*/

const int LED_ROJO = 11;
const int LED_AZUL = 10;
const int LED_VERDE = 9;
const int RETARDO = 500;

void setup() {

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

}

void loop() {

  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(RETARDO);

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AZUL, HIGH);
  digitalWrite(LED_VERDE, LOW);
  delay(RETARDO);

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(RETARDO);

}
