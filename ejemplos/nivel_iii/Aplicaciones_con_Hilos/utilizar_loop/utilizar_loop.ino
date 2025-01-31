/*
    Datalogger - Agosto de 2022

    Hardware:
    ---------

    Tarjeta SD, utiliza la librería integrada y se
    conecta vía el bus SPI:

      CS/SS/SDA     -- pin 10
      MOSI/SDI/DIN  -- pin 11
      MISO/SDO/DOUT -- pin 12
      CLK/SCK/SCLK  -- pin 13

    LCD con expansor PCF8574. Utiliza la librería
    LiquidCrystal I2C de Marco Schwartz, y se conecta
    mediante el bus I2C en la dirección 0x27.

    RTC DS1307. Utiliza la librería RTClib de Adafruit,
    y se conecta al bus I2C en la dirección 0x68.

*/

#include <LiquidCrystal_I2C.h>
#include <Thread.h>
#include <SPI.h>
#include <SD.h>
#include "RTClib.h"
#include "DHT.h"

//Objetos
LiquidCrystal_I2C pantalla(0x27, 16, 2);
DHT sensor(2, DHT11);
RTC_DS1307 reloj;
File archivo;

//Variables y constantes
const int LED = 3;
byte grados[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {

  pinMode(LED, OUTPUT);

  pantalla.init();
  pantalla.backlight();
  pantalla.createChar(0, grados);
  pantalla.setCursor(0, 0);
  pantalla.print("Iniciar SD...");
  pantalla.setCursor(0, 1);

  sensor.begin();

  if (!SD.begin(10)) {
    pantalla.print("...fallo!");
    while (1);
  }
  pantalla.print("...listo!");

  if (! reloj.begin()) {
    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("Falla RTC");
    while (1) delay(10);
  }

  if (! reloj.isrunning()) {
    //Ajusta el RTC con la fecha y hora de compilación del sketch.
    reloj.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Ajusta el RTC con el siguiente formato: Enero 21, 2022 3am
    // rtc.adjust(DateTime(2022, 1, 21, 3, 0, 0));
  }

}

void loop() {

  //Lectura del sensor
  float humedad = sensor.readHumidity();
  float temperatura = sensor.readTemperature();

  //Lectura del RTC
  DateTime now = reloj.now();

  //LED testigo
  static bool ledStatus = false;
  ledStatus = !ledStatus;
  digitalWrite(LED, ledStatus);

  //String AAAA/DD/MM HH:MM
  String tiempo = String(now.year()) + "/" + String(now.month()) + "/" +
                  String(now.day()) + " " + String(now.hour()) + ":" +
                  String(now.minute());

  //String HH.HH%RH TT.TT°C
  String lectura = String(humedad) + "%RH " + String(temperatura) + " C";

  //Escritura en pantalla
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print(tiempo);
  pantalla.setCursor(0, 1);
  pantalla.print(lectura);
  pantalla.setCursor(14, 1);
  pantalla.write(0); //Simbolo grados

  delay(3000);

  //Guardar datos en la tarjeta SD
  // Abrir el archivo como R/W, si no existe se creará
  archivo = SD.open("DATA.csv", FILE_WRITE);

  // Si se pudo abrir el archivo, guardamos datos
  if (archivo) {
    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("Escribiendo...");
    archivo.print(tiempo);
    archivo.print(",");
    archivo.println(lectura);
    archivo.close();
    pantalla.setCursor(0, 1);
    pantalla.print("...terminado!");
  } else {
    pantalla.print("Error al abrir");
  }

  delay(2000);
}
