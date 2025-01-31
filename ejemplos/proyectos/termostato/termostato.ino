/*
  Termostato
  Miércoles 21 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/lSWoiZnhykX

*/

// librería lcd
#include <LiquidCrystal.h>

// configuración del pinout de la pantalla
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
const int RELE = 13;
const int SENSOR = A1;

LiquidCrystal pantalla(RS, EN, D4, D5, D6, D7);

void setup() {

  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, LOW);

  pantalla.begin(16, 2);
  pantalla.print("SENSOR TEMP.:");

}

void loop() {

  //lectura y conversión sensor
  int lectura = analogRead(SENSOR);
  float tension = 5.0 / 1024 * lectura;
  float temperatura = tension * 100 - 50;

  //muestra temperatura en pantalla
  pantalla.setCursor(10, 1);
  pantalla.print(temperatura);

  //según un rango de temperatura enciendo una lampara
  if (lectura > 163) {
    digitalWrite(RELE, HIGH);
  }

  if (lectura < 144) {
    digitalWrite(RELE, LOW);
  }

}
