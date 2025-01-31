/*
  Sensor de movimiento tipo PIR
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/27paYkwxIIX

*/

const int SENSOR_PIR = 2;

void setup() {
  pinMode(SENSOR_PIR, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(SENSOR_PIR) == HIGH) {
    Serial.println("Intruso detectado!!!");
  }

}
