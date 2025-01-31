/*
    Ejemplo de uso de una tarjeta SD (v3) con archivos CSV
    https://es.wikipedia.org/wiki/Valores_separados_por_comas

    La tarjeta SD se conecta vía el bus SPI:

    CS/SS/SDA     -- pin 10
    MOSI/SDI/DIN  -- pin 11
    MISO/SDO/DOUT -- pin 12
    CLK/SCK/SCLK  -- pin 13
*/

#include <SPI.h>
#include <SD.h>

File archivo;
int temperatura = 8;
int hora = 10;

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
  temperatura = temperatura * 2;
  hora++;
  
  // Abrir el archivo como R/W, si no existe se creará
  archivo = SD.open("DATA.csv", FILE_WRITE);

  // Si se pudo abrir el archivo, guardamos datos
  if (archivo) {
    Serial.print("Escribiendo en el archivo...");
    // formato: hora, temperatura
    archivo.print(hora);
    archivo.print(",");
    archivo.println(temperatura);
    archivo.close();
    Serial.println(" terminado");
  } else {
    Serial.println("Error al abrir el archivo");
  }

  delay(1000);
}
