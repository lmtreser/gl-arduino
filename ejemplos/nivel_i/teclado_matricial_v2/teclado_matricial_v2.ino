/*
  Teclado Matricial en un solo pin
  Martes 3 de noviembre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/lVYZWUGUuKh 

*/

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  
   int tecla = analogRead(A0);
   Serial.println(tecla);
}
