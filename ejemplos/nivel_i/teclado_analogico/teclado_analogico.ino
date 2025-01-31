/*
  Teclado analógico
  Martes 3 de noviembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/cVYnjKZaJKM

*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int tecla = analogRead(A0);
  Serial.println(tecla);
}
