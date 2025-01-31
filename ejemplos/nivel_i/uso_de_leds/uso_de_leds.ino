/* USO DE LEDS
   Prácticas con Arduino
*/

void setup() {

  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {

  digitalWrite(13, HIGH);
  digitalWrite(7, LOW);
  delay(500);
  digitalWrite(13, LOW);
  digitalWrite(7, HIGH);
  delay(500);

}
