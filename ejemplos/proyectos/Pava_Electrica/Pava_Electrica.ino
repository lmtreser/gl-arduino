/*
 * Proyecto Automatización de Pava Eléctrica
 * Miércoles 13 de octubre de 2021
 */

// Librerías
#include <OneWire.h>
#include <DallasTemperature.h>

// Objetos del sensor de temperatura
OneWire oneWire(2);
DallasTemperature temperatura(&oneWire);

// Constantes
const int RELE = 7;
const int GRADO = 26;

void setup() {

  pinMode(RELE, OUTPUT);
  Serial.begin(9600);
  temperatura.begin(); // Iniciar sensor de temperatura

}

void loop() {

  // Leer y almacenar la temperatura
  temperatura.requestTemperatures();
  float sensor = temperatura.getTempCByIndex(0);

  // Lógica de trabajo
  if (sensor > GRADO){
    digitalWrite(RELE, LOW);
  } 
  else{
    digitalWrite(RELE, HIGH);
  }

  // Mostrar la temperatura en la consola
  Serial.print("Temperatura: ");
  Serial.print(sensor);
  Serial.println(" °C");

}
