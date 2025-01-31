// Monitoreo de cultivo de hongos comestibles

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);

byte grados[] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup() {

  lcd.begin();
  lcd.backlight();
  lcd.createChar(0, grados);
  dht.begin();

}

void loop() {

  //lectura de sensores
  int sensorSustrato = analogRead(A0);
  int humedad = dht.readHumidity();
  int temperatura = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(temperatura);
  lcd.write(0);
  lcd.print("C | ");
  lcd.print("H: ");
  lcd.print(humedad);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Sustrato:     ");
  lcd.setCursor(10, 1);
  lcd.print(sensorSustrato);

  delay(1000);

}
