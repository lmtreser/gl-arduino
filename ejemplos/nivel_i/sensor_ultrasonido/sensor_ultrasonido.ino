/*
  Sensor de distancia por ultrasonido
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
   https://www.tinkercad.com/things/58HBW7qjMpg

*/

// Libreria por Erick Simões
// github: @ErickSimoes
// twitter: @AloErickSimoes
#include <Ultrasonic.h>

// trigger y echo pin
Ultrasonic ultrasonic(2, 3);
int distancia;

void setup() {
  Serial.begin(9600);
}

void loop() {

  distancia = ultrasonic.read();

  Serial.print("Distancia en CM: ");
  Serial.println(distancia);
  delay(1000);
}
