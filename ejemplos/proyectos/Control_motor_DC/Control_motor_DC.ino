/*
   CONTROL DE MOTOR DC
   10/11/2021
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CONTROL DE MOTOR");
}

void loop() {

  // Lectura del sensor
  int potenciometro = analogRead(A0);
  Serial.print("Lectura: ");
  Serial.println(potenciometro);

  // Control de potencia
  potenciometro = potenciometro / 4;
  analogWrite(9, potenciometro);

  // Mostrar mensaje en pantalla
  lcd.setCursor(0,1);
  lcd.print(potenciometro);

  if(potenciometro < 100) {
    lcd.setCursor(2, 1);
    lcd.print(" ");
  }
  
  delay(100);
}
