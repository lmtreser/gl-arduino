/*
   Ejemplo de uso de la librería "LiquidMenu"
   Pantalla LCD 16*2 I2C

   https://github.com/VasilKalchev/LiquidMenu

*/

// Librerías necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>

// Dirección del módulo en 0x27 para una pantalla 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pines del encoder
const byte CLK = 2;
const byte DT = 3;
const byte SW = 4;

// Pines de sensores
const byte analogPin = A1;

// Variables utilizadas por el encoder
int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

// Variables que simulan el cambio de estado del sensor
unsigned short analogReading = 0;
unsigned short lastAnalogReading = 0;
unsigned int period_check = 1000;
unsigned long lastMs_check = 0;

// Un objeto LiquidLine representa una linea de texto y/o variables
// en la pantalla. El primer parametro es la columna y la fila desde
// donde comenzará la línea, el resto de los parametros son el texto
// y/o las variables que serán mostradas. Pueden ser hasta cuatro.

// Línea para la pantalla de bienvenida, columna 1, fila 0
LiquidLine welcome_line1(1, 0, "LiquidMenu ", LIQUIDMENU_VERSION);
// Línea para la pantalla de bienvenida, columna 1, fila 1
LiquidLine welcome_line2(1, 1, "Ejemplo de uso");

// Un objeto LiquidScreen representa una pantalla. Una pantalla puede
// estar constituida de uno o más objetos LiquidLine. Hasta cuatro
// objetos LiquidLine pueden ser insertados desde aquí, pero más pueden
// agregarse en la función setup() usando el metodo:
// welcome_screen.add_line(someLine_object);

// Pantalla de bienvenida
LiquidScreen welcome_screen(welcome_line1, welcome_line2);

// Definición de líneas y pantalla secundaria
LiquidLine analogReading_line(0, 0, "Temperatura: ", analogReading);
LiquidScreen secondary_screen(analogReading_line);

// El objeto LiquidMenu combina los objetos LiquidScreen para armar el menu
// Las pantallas son agregadas despues usando el método:
// menu.add_screen(someScreen_object);
// Este objeto es usado para controlar el menu, por ejemplo:
// menu.next_screen();
// menu.switch_focus();
LiquidMenu menu(lcd);

void setup() {

  // Configuración de pines
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT);

  // Inicializar el LCD
  lcd.init();
  lcd.backlight();

  // Este metodo es usado para agregar pantallas al objeto menu
  menu.add_screen(welcome_screen);
  menu.add_screen(secondary_screen);

  // Leer el estado inicial de CLK (encoder)
  lastStateCLK = digitalRead(CLK);

}

void loop() {

  // Lectura periodica del pin analógico
  if (millis() - lastMs_check > period_check) {

    lastMs_check = millis();
    analogReading = analogRead(analogPin);

    // Si el valor del sensor cambio, será mostrado
    if (analogReading != lastAnalogReading) {
      lastAnalogReading = analogReading;
      // Actualizar solo en la pantalla correcta
      menu.update();
    }
  }

  // Lectura del encoder
  currentStateCLK = digitalRead(CLK);

  // Si el último y actual estado de CLK son diferentes
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {

    // Encoder girando en sentido CCW, decrementar
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      menu.change_screen(1);
    } else {
      // Encoder girando en sentido CW, incrementar
      counter ++;
      menu.change_screen(2);
    }
  }

  lastStateCLK = currentStateCLK;   // Almacenar el último estado de CLK
  int btnState = digitalRead(SW);   // Leer el estado del pulsador

  // Si se detecta una señal LOW, el botón fue presionado
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      menu.next_screen();   // Pasa a la siguiente pantalla
    }
    lastButtonPress = millis();   // Almacenar el tiempo del último evento de botón
  }

  delay(1);

}
