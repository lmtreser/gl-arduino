/*
  Pulsadores y rebotes
  Sábado 3 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/cDnWGgietEf

*/

const int PULSADOR = 12;
boolean pulsEstado = 0;
boolean ledEstado = 0;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PULSADOR, INPUT_PULLUP);

}

void loop() {

  if (digitalRead(PULSADOR) == LOW) {
    pulsEstado = 1;
  }
  if ((digitalRead(PULSADOR) == HIGH) && (pulsEstado == 1)) {
    pulsEstado = 0;
    ledEstado = !ledEstado;
    digitalWrite(LED_BUILTIN, ledEstado);
  }
}
