/*
  Control de motor CC
  Viernes 2 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/6Whw7FsExXV

  Tabla de verdad:

  1A    2A    EN    CONDICIÓN
  --------------------------------
  HIGH  LOW   PWM   GIRO IZQUIERDA
  LOW   HIGH  PWM   GIRO DERECHA
  HIGH  HIGH  PWM   FRENO
  LOW   LOW   PWM   FRENO
  H/L   L/H    0    FRENO

  PWM: puede variar entre 0 y 255

*/

const int MOTOR_1A = 2;
const int MOTOR_2A = 4;
const int MOTOR_EN = 3;

void setup() {

  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_2A, OUTPUT);

}

void loop() {

  izquierda(50);
  delay(2000);
  freno();
  delay(2000);
  derecha(255);
  delay(2000);
  freno();
  delay(2000);

}

//función giro a la izquierda
void izquierda(int velocidad) {
  analogWrite(MOTOR_EN, velocidad);
  digitalWrite(MOTOR_1A, HIGH);
  digitalWrite(MOTOR_2A, LOW);
}

//función giro a la izquierda
void derecha(int velocidad) {
  analogWrite(MOTOR_EN, velocidad);
  digitalWrite(MOTOR_1A, LOW);
  digitalWrite(MOTOR_2A, HIGH);
}

//función freno
void freno() {
  digitalWrite(MOTOR_1A, LOW);
  digitalWrite(MOTOR_2A, LOW);
}
