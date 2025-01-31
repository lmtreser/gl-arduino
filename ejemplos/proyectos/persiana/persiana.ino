/*
  Automatización de una persiana
  Usando una LDR
  Miércoles 28 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/6YaaRrzYX9G 

*/

const int SENSOR = A2;
const int CARRERA_INFERIOR = 2;
const int CARRERA_SUPERIOR = 3;
const int MOTOR_1A = 12;
const int MOTOR_2A = 13;
const int MOTOR_EN = 11;

void setup() {
  
  pinMode(CARRERA_INFERIOR, INPUT);
  pinMode(CARRERA_SUPERIOR, INPUT);
  pinMode(MOTOR_1A, OUTPUT);
  pinMode(MOTOR_2A, OUTPUT);
  Serial.begin(9600);

}


void loop() {

  int luz = analogRead(SENSOR);
  Serial.print("El sensor devuelve: ");
  Serial.println(luz);
    
}