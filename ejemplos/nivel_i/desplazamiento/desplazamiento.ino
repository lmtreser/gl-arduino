/*
  Registro de desplazamiento 74HC595
  Martes 3 de noviembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/eVnENIgBcN1

  shiftOut()
  https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/

*/

const int LATCHPIN = 3; //RCLK
const int CLOCKPIN = 4; //SRCLK
const int DATAPIN = 2;  //SER

byte datos;

void setup() {
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(DATAPIN, OUTPUT);

  digitalWrite(LATCHPIN, LOW);
}

void loop() {

  datos = B10101010; //dato a enviar
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, datos);
  digitalWrite(LATCHPIN, HIGH);
  digitalWrite(LATCHPIN, LOW);
  delay(1000);

  datos = B01010101; //dato a enviar
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, datos);
  digitalWrite(LATCHPIN, HIGH);
  digitalWrite(LATCHPIN, LOW);
  delay(1000);
}
