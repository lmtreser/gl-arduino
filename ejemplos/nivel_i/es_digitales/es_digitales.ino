/*
  Arduino Entradas y Salidas Digitales
  Domingo 13 de septiembre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/7vwuGjzJwqK

*/

// constantes
const int BOTON = 2;
const int LED_ROJO = 13;
const int LED_VERDE = 10;

void setup() {
  pinMode(BOTON, INPUT);
  pinMode(LED_VERDE, OUTPUT); // conecto un LED a la pata 10
  pinMode(LED_ROJO, OUTPUT);  // conecto un LED a la pata 13
}

void loop() {

  // Si el pulsador está en un nivel alto
  if (digitalRead(BOTON) == HIGH) {
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_VERDE, LOW);
  }
  else { // Si el pulsador está en un nivel bajo
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_ROJO, LOW);
  }
  delay(10); // demora para mejorar la simulación
}
