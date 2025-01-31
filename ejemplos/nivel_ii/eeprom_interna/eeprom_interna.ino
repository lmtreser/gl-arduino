/*
    EEPROM R/W
    Almacenar y recuperar datos de la memoria EEPROM interna
    del microcontrolador.
    Martes 3 de mayo de 2022

    EEPROM Library
    https://docs.arduino.cc/learn/built-in-libraries/eeprom

    A guide to EEPROM
    https://docs.arduino.cc/learn/programming/eeprom-guide

    EEPROM (DATA MEMORY)
    ---------------------
    |                   | 0x0000
    |                   |
    |                   |
    |                   |
    |                   | EEPROMEND
    ---------------------
    |<---  8 bits   --->|

*/

#include <EEPROM.h>

// Variable utilizada para direccionar la memoria
int address = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {

  // Datos aleatorios a guardar
  int valor = random(0, 10);

  // Escribir un valor en la memoria
  EEPROM.write(address, valor);

  // Leer el dato almacenado
  int dato = EEPROM.read(address);

  Serial.print("Dato a guardar: ");
  Serial.print(valor);
  Serial.print("   Direccion: ");
  Serial.print(address);
  Serial.print("   Dato leido: ");
  Serial.println(dato);

  // Recorrer todo el espacio de memoria
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }

  delay(5000);
}
