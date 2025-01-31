/*
    Datalogger - Agosto de 2022
    Versión con la función millis() y condiciones.

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
const int TAREA_1 = 500;
const int TAREA_2 = 2000;
const int TAREA_3 = 5000;

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

  static unsigned long tiempoTarea1 = 0;
  static unsigned long tiempoTarea2 = 0;
  static unsigned long tiempoTarea3 = 0;

  if (millis() > tiempoTarea1 + TAREA_1) {
    tiempoTarea1 = millis();
    toogle();
  }

  if (millis() > tiempoTarea2 + TAREA_2) {
    tiempoTarea2 = millis();
    String datosRtc = getTime();
    String datosDht = getSensor();
    writeLCD(datosRtc, datosDht);
  }

  if (millis() > tiempoTarea3 + TAREA_3) {
    tiempoTarea3 = millis();
    String datosRtc = getTime();
    String datosDht = getSensor();
    saveSD(datosRtc, datosDht);
  }

}

String getTime() {
  DateTime now = reloj.now();
  String tiempo = String(now.year()) + "/" + String(now.month()) + "/" +
                  String(now.day()) + " " + String(now.hour()) + ":" +
                  String(now.minute());
  return tiempo;
}

String getSensor() {
  float humedad = sensor.readHumidity();
  float temperatura = sensor.readTemperature();
  String lectura = String(humedad) + "%RH " + String(temperatura) + " C";
  return lectura;
}

void writeLCD(String tiempo, String lectura) {
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print(tiempo);
  pantalla.setCursor(0, 1);
  pantalla.print(lectura);
  pantalla.setCursor(14, 1);
  pantalla.write(0); //Simbolo grados
}

void saveSD(String tiempo, String lectura) {
  archivo = SD.open("DATA.csv", FILE_WRITE);
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
}

void toogle() {
  static bool ledStatus = false;
  ledStatus = !ledStatus;
  digitalWrite(LED, ledStatus);
}
