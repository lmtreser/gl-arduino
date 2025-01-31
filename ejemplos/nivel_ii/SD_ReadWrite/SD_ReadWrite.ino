/*
  SD card read/write

  La tarjeta SD se conecta vía el bus SPI:

  MOSI/SDI/DIN  -- pin 11
  MISO/SDO/DOUT -- pin 12
  CLK/SCK/SCLK  -- pin 13
  CS/SS/SDA     -- pin 4

  La librería incorpora funciones para el manejo de archivos y directorios
  mediante el objeto SD:

  SD.begin(cspin);          // Iniciar la SD
  SD.exists(filename);      // Comprobar si existe un archivo (devuelve true)
  SD.remove(filename);      // Borrar un archivo
  SD.open(filepath, mode);  // Abrir un archivo, FILE_READ (R), FILE_WRITE (RW)
  SD.mkdir(directory);      // Crear un directorio
  SD.rmdir(dirname);        // Eliminar un directorio

  La librería incorpora funciones para la lectura y escritura de archivos
  mediante el objeto File:

  file.size()               // Devuelve el tamaño de un archivo
  file.available()          // Comprueba si quedan bytes por leer
  file.read()               // Leer un byte del archivo
  file.write(data)          // Escribir un byte en el archivo
  file.print(data)          // Escribir una variable en un archivo
  file.position()           // Obtener el punto de lectura/escritura actual
  file.seek(pos)            // Mover el punto de lectura/escritura actual
                            // Pos: Debe estar entre 0 y file.size()
  file.close()              // Cerrar el archivo

  https://www.luisllamas.es/tarjeta-micro-sd-arduino/

*/

#include <SPI.h>
#include <SD.h>

File miArchivo;

void setup() {

  Serial.begin(9600);
  Serial.print("Inicializando la tarjeta SD...");

  if (!SD.begin(4)) {
    Serial.println("falló!");
    while (1);
  }
  Serial.println("listo.");

  // Abrir el archivo. Sólo es posible abrir un archivo a la vez
  miArchivo = SD.open("pruebas.txt", FILE_WRITE);

  if (miArchivo) {
    Serial.print("Escribiendo en pruebas.txt...");
    miArchivo.println("1, 2, 3... Probando");
    miArchivo.close();
    Serial.println("listo.");
  } else {
    Serial.println("error al abrir pruebas.txt");
  }

  // Abrir el archivo para lectura
  miArchivo = SD.open("pruebas.txt");
  if (miArchivo) {

    Serial.println("pruebas.txt:");
    while (miArchivo.available()) {
      Serial.write(miArchivo.read());
    }
    miArchivo.close();
  } else {
    Serial.println("error abriendo pruebas.txt");
  }
}

void loop() {

}
