
/*
  Registro de desplazamiento 74HC595 (doble)
  Martes 3 de noviembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/jFwhMbgjvMt

  shiftOut()
  https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/

*/

const int LATCHPIN = 3; //RCLK
const int CLOCKPIN = 4; //SRCLK
const int DATAPIN = 2;  //SER

byte datosAlto = B00001111;
byte datosBajo = B11110000;

void setup() {
  
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(DATAPIN, OUTPUT);

  digitalWrite(LATCHPIN, LOW);
}

void loop() {

  // envia la parte alta del byte
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, datosAlto);
  // envia la parte baja del byte
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, datosBajo);

  // pulso para que pase al registro de salida
  digitalWrite(LATCHPIN, HIGH); // pulso ALTO
  digitalWrite(LATCHPIN, LOW); // pulso BAJO
}
