/*  Registrador de datos (Datalogger)
    Lucas Martín Treser -- 06/07/2022

    El dispositivo utiliza el sensor DHT11 para tomar datos de
    temperatura y humedad cada cierto período de tiempo definible
    por el usuario y luego vuelca los datos a una tarjeta SD en
    un archivo CSV. La tarjeta SD se conecta vía el bus SPI en
    los siguientes pines de un Arduino Uno:

    CS/SS/SDA     -- pin 10
    MOSI/SDI/DIN  -- pin 11
    MISO/SDO/DOUT -- pin 12
    CLK/SCK/SCLK  -- pin 13

    El sensor se encuentra conectado al pin digital #2 y un LED
    testigo en el pin digital #3.
    
*/

#include <SPI.h>
#include <SD.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

//objetos
File archivo;
DHT sensorHT(DHTPIN, DHTTYPE);

//constantes (segundos)
const int PERIODO = 1000;
const int EVENTO = 1;
const int LED = 3;

//variables
unsigned long tiempoActual = 0;
byte estado = HIGH;
int t_year = 2022;
int t_month = 7;
int t_day = 11;
int t_hour = 14;
int t_minute = 2;
int t_second = 0;

void setup() {

  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.print("Inicializando SD...");
  sensorHT.begin();

  if (!SD.begin(10)) {
    Serial.println("falló!");
    while (1);
  }
  Serial.println("listo!");
}

void loop() {

  //rutina que se ejecuta cada cierto PERIODO de tiempo
  if (millis() >= (tiempoActual + PERIODO)) {

    toogle(); //cambia el estado del LED 13
    tiempoActual = millis(); //actualiza el tiempo actual
    t_second++;

    if (t_second > 59) {
      t_second = 0; //reinicia el segundero
      t_minute++; //incrementa minutero
    }

    if (t_minute > 59) {
      t_minute = 0; //reinicia el minutero
      t_hour++; //incrementa horas
    }

    //despues de transcurrido el tiempo, se origina un EVENTO
    if (t_second == EVENTO) {
      
      //obtener los datos del sensor
      float t_humedad = sensorHT.readHumidity();
      float t_temperatura = sensorHT.readTemperature();

      //muestro los valores en terminal, solo para depuracion
      Serial.print("H: ");
      Serial.print(t_humedad);
      Serial.print(", T: ");
      Serial.println(t_temperatura);
      
      //generar el timestamp
      unsigned long t_hora = stampHora();
      unsigned long t_fecha = stampFecha();
      
      //grabar los datos en la tarjeta SD
      grabarSD(t_hora, t_fecha, t_humedad, t_temperatura);
    }
  }
}

//funcion que genera un timestamp para la fecha
unsigned long stampFecha() {
  unsigned long fecha = t_day * 1000000UL + t_month * 10000UL + t_year;
  return fecha;
}

//funcion que genera un timestamp para la hora
unsigned long stampHora() {
  unsigned long hora = t_hour * 10000UL + t_minute * 100 + t_second;
  return hora;
}

//funcion que genera un toogle en un LED
void toogle() {
  estado = !estado;
  digitalWrite(LED, estado);
}

void grabarSD(unsigned long hora, unsigned long fecha, float humedad, float temperatura) {

  // Abrir el archivo como R/W, si no existe se creará
  archivo = SD.open("DATA.csv", FILE_WRITE);

  // Si se pudo abrir el archivo, guardamos datos
  if (archivo) {
    Serial.print("Escribiendo en el archivo...");
    // formato: hora, fecha, humedad, temperatura
    archivo.print(hora);
    archivo.print(",");
    archivo.print(fecha);
    archivo.print(",");
    archivo.print(humedad);
    archivo.print(",");
    archivo.println(temperatura);
    archivo.close();
    Serial.println(" terminado");
  } else {
    Serial.println("Error al abrir el archivo");
  }
}
