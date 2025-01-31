/*
  Sensor de temperatura TMP36
  Viernes 2 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
   https://www.tinkercad.com/things/6nTPHEvClok

*/

const int SENSOR_TEMP = A0;

void setup() {

  Serial.begin(9600);

}

void loop() {

  int lectura = analogRead(SENSOR_TEMP);
  float tension = 5.0 / 1024 * lectura;
  float temperatura = tension * 100 - 50;

  Serial.print("RAW: ");
  Serial.print(lectura);
  Serial.print(" | Temperatura: ");
  Serial.println(temperatura);
  delay(1000);

}
