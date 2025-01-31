/*
  Automatización Crepuscular
  Usando una LDR
  Miércoles 30 de septiembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/azQVyQTxm6W

*/

const int SENSOR_LDR = A0;
int luz; // declaro variable del sensor

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}


void loop() {

  luz = analogRead(SENSOR_LDR);
  Serial.print("El sensor devuelve: ");
  Serial.println(luz);

  // si el sensor está en un valor bajo
  // tiene que encender el puerto 13
  if (luz <= 20) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(10); // sólo para simulación
}
