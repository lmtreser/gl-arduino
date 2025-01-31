/*
  Pantalla LCD 16*2
  Miércoles 30 de septiembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/llxWLfqLUIW

*/

// librería lcd
#include <LiquidCrystal.h>

// configuración del pinout de la pantalla
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal pantalla(RS, EN, D4, D5, D6, D7);

void setup() {

  pantalla.begin(16, 2);
  pantalla.print("Hola mundo!");
}

void loop() {

  // Cursor a columna 0, linea 1
  pantalla.setCursor(0, 1);
  // Mostrar variable
  pantalla.print(millis() / 1000);

}
