/*
  Ejemplo de uso de una tarjeta SD (v2)
  https://naylampmechatronics.com/blog/38_tutorial-arduino-y-memoria-sd-y-micro-sd.html

  La tarjeta SD se conecta vía el bus SPI:

  CS/SS/SDA     -- pin 10
  MOSI/SDI/DIN  -- pin 11
  MISO/SDO/DOUT -- pin 12
  CLK/SCK/SCLK  -- pin 13

*/

#include <SPI.h>
#include <SD.h>

File archivo;

int temperatura = 10;

void setup() {

  Serial.begin(9600);
  Serial.print("Inicializando la tarjeta SD...");

  if (!SD.begin(10)) {
    Serial.println("falló!");
    while (1);
  }
  Serial.println("listo.");
}

void loop() {

  // Simulación de un sensor de temperatura
  temperatura++;
  
  // Abrir el archivo como R/W, si no existe se creará
  archivo = SD.open("SENSOR.log", FILE_WRITE);

  // Si se pudo abrir el archivo, guardamos datos
  if (archivo) {
    Serial.print("Escribiendo en el archivo...");
    archivo.print(__DATE__); // Esta macro obtiene la fecha de la PC (al compilar)
    archivo.print(" - ");
    archivo.print(__TIME__); // Esta macro obtiene la hora de la PC (al compilar)
    archivo.print(" - Temperatura (°C): ");
    archivo.println(temperatura);
    archivo.close();
    Serial.println(" terminado");
  } else {
    Serial.println("Error al abrir el archivo");
  }

  delay(2000);
}
