/*
  Control de un servo
  Viernes 2 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/h5XEEa9sCJg

*/

//Librería y objeto servo
#include <Servo.h>
Servo servoMotor;

void setup() {

  servoMotor.attach(11);

}

void loop() {

  // Desplazamos a la posición 0º
  servoMotor.write(0);
  delay(1000);

  // Desplazamos a la posición 90º
  servoMotor.write(90);
  delay(1000);

  // Desplazamos a la posición 180º
  servoMotor.write(180);
  delay(1000);

}
