/* Lectura de temperatura y humedad ambiente
   Visualización de datos mediante SerialStudio
   Automatismos Mar del Plata - Marzo 2021
   https://www.automatismos-mdq.com.ar/
*/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  // lectura del sensor
  float tempc = dht.readTemperature();
  float tempf = dht.readTemperature(true);
  float humedad = dht.readHumidity();
  float stc = dht.computeHeatIndex(tempc, humedad, false);
  float stf = dht.computeHeatIndex(tempf, humedad);

  // formateo de datos
  String json = "/*" + String(tempc, 2) + "," + String(tempf, 2) + "," + String(humedad, 2)
                + "," + String(stc, 2) + "," + String(stf, 2) + "," + millis() + "*/";
  Serial.println(json);

  delay(2000);
}
