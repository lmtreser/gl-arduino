/*
    Ejemplo de uso la interrupción del Timer 1
*/

#include <TimerOne.h>

//Constantes y variables
const int LED = 3;
int estado = LOW;
volatile unsigned long contador = 0;

//Funcion a llamar desde la interrupcion
void blinkLED() {
  if (estado == LOW) {
    estado = HIGH;
    contador++;
  } else {
    estado = LOW;
  }
  digitalWrite(LED, estado);
}

void setup() {

  pinMode(LED, OUTPUT);

  // blinkLED se ejecutará cada 0.15 segundos
  Timer1.initialize(150000);
  Timer1.attachInterrupt(blinkLED);
  Serial.begin(9600);
}

void loop(void) {

  /*Para leer una variable que está siendo escrita por la interrupción
    debemos deshabilitar la interrupción temporalmente, para asegurarnos
    de que no sea alterada durante el proceso de lectura. Para minimizar el
    tiempo que la interrupción se encuentra apagada, solo hacemos una copia,
    y entonces usamos la copia mientras permitimos a la interrupción seguir
    trabajando.
  */
  unsigned long copiaContador;
  noInterrupts();
  copiaContador = contador;
  interrupts();

  Serial.print("Cantidad de destellos: ");
  Serial.println(copiaContador);
  delay(100);
}
