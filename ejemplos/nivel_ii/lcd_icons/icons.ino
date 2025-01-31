/*
  Librería LiquidCrystal: Caracteres personalizados

  Simulación en:
  https://wokwi.com/projects/355666401414041601
  
  Algunos enlaces de interés:
  http://www.arduino.cc/en/Tutorial/LiquidCrystalCustomCharacter
  https://www.automatismos-mdq.com.ar/blog/2020/12/generador-de-caracteres-especiales-para-lcd.html
  https://www.automatismos-mdq.com.ar/blog/tools/LCD_ccg/lcd-ccg.html
  
*/

#include <LiquidCrystal.h>
#include "icons.h"

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);

  // crear nuevos caracteres
  lcd.createChar(0, arrowUp);
  lcd.createChar(1, lock);
  lcd.createChar(2, unlock);
  lcd.createChar(3, heart);
  lcd.createChar(4, degrees1);
  lcd.createChar(5, degrees2);
  lcd.createChar(6, hum);
  lcd.createChar(7, temp);

  lcd.setCursor(0, 0);
  lcd.print("Set de iconos:");

  lcd.setCursor(0, 1);
  lcd.write(byte(0));  // El '0' debe ser casteado como byte
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);

  // Ejemplo temperatura y humedad  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(7);
  lcd.setCursor(1, 0);
  lcd.print(" 30 C");
  lcd.setCursor(4, 0);
  lcd.write(5);
  lcd.setCursor(6, 0);
  lcd.print("    70%RH");
  lcd.setCursor(8, 0);
  lcd.write(6); 

}

void loop() {
  // ...
}
