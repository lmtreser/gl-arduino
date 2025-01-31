/*
  Sensor de inclinación
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/gvQzqipMO5D

*/
const int SENSOR = 2;

void setup() {

  pinMode(SENSOR, INPUT);
  Serial.begin(9600);

}

void loop() {

  Serial.print("Estado: ");
  Serial.println(digitalRead(SENSOR));

}
