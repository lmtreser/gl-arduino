/*
  Termometro digital
  Miércoles 14 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/799cCrXWUG4

*/

// librería lcd
#include <LiquidCrystal.h>

// configuración del pinout de la pantalla
const int RS = 2;
const int EN = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;
const int SENSOR = A1;

LiquidCrystal pantalla(RS, EN, D4, D5, D6, D7);

void setup() {

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

}
