/*
  RETARDO NO BLOQUEANTE
  Uso de la función millis()
  Sábado 3 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/a32xqxeewZs

*/

const int LED_VERDE = 10;
const int PULS = 2;
const int TIEMPO = 500;

unsigned long tiempoActual = 0;
boolean ledaEstado;
boolean ledvEstado;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(PULS, INPUT_PULLUP);

}

void loop() {

  //retardo no bloqueante
  if (millis() > (tiempoActual + TIEMPO)) {
    tiempoActual = millis();
    ledaEstado = ! ledaEstado;
    digitalWrite(LED_BUILTIN, ledaEstado);
  }

  //lectura del pulsador
  if (digitalRead(PULS) == LOW) {
    ledvEstado = ! ledvEstado;
    digitalWrite(LED_VERDE, ledvEstado);
  }
}
