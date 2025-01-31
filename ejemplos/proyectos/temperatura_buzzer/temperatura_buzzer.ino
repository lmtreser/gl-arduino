// Sensor de temperatura + LCD + Buzzer
// Miércoles 17 de noviembre de 2021


// Librerías necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Crear el objeto pantalla
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);

void setup() {

  lcd.init();       // Inicializar la pantalla
  lcd.backlight();  // Encender el backlight
  lcd.print("SENSOR IS-213"); // Mostrar un mensaje
  dht.begin();
}

void loop() {

  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  lcd.setCursor(0, 1);
  lcd.print(humedad);
  lcd.setCursor(8, 1);
  lcd.print(temperatura);

  if (temperatura > 25) {
    tone(8, 1000, 500);
  }

  delay(2000);

}
