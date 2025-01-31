/*
	Lectura de entrada analógica, salidas PWM
  Domingo 13 de septiembre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/hs15RMjqEvm

*/

int valorSensor;
const int SALIDA_LED = 9;
const int POTENCIOMETRO = A0;

void setup() {

  pinMode(SALIDA_LED, OUTPUT);
  Serial.begin(9600); // habilito la consola serie

}

void loop() {

  /* A0 maneja valores de 0 a 1023
  	 PWM maneja valores de 0 a 255
  */

  valorSensor = analogRead(POTENCIOMETRO) / 4;
  analogWrite(SALIDA_LED, valorSensor);
  Serial.println(valorSensor);

  delay(10); // solo para simulación
}
