/*
   USO DE INTERRUPCIONES: BLINK
   Ejemplo #1 - Agosto de 2022

  Se deberá conectar un cable desde el pin digital #10
  (generador del evento) al pin de interrupción (digital #2).

*/

// Constantes y variables
const int eventoPin = 10;
const int interruptPin = 2;
volatile int estado = LOW;

void setup() {

  pinMode(eventoPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  // Configurar una interrupción en el pin digital 2, es posible
  // usar la funcion digitalPinToInterrupt(interruptPin):
  // attachInterrupt(digitalPinToInterrupt(intPin), blink, CHANGE);
  attachInterrupt(INT0, blink, CHANGE);

}

void loop() {

  // Generación de un evento para interrumpir al Arduino
  digitalWrite(eventoPin, HIGH);
  delay(300);
  digitalWrite(eventoPin, LOW);
  delay(300); 
}


// Función callback (ISR) que hace destellar el LED conectado
// al pin digital #13
void blink() {
  estado = !estado;
  digitalWrite(LED_BUILTIN, estado);
}
