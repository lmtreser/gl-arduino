/*
   Una máquina de estados es un programa que reacciona no solo en función
   de las entradas que tiene, sino también del estado en que se encuentra.
   Por ejemplo, un lavarropas tendrá tres estados: Standby, Lavado y Centrifugado.

   El siguiente ejemplo, describe una máquina de estados que funciona solo con un
   botón, depende en que estado estemos el resultado de pulsarlo será uno:

   1- Standby. Estado de pausa. Nuestra lavarropas estará quieto. Cuando pulsemos un
   botón pasará al estado de Lavado.

   2- Lavado. Nuestra lavarropas empieza a girar y ejecutará el programa de lavado.
   Cuando finalice el tiempo de lavado la máquina dejara de girar unos segundos y
   pasará al estado de Centrifugado.

   3- Centrifugado. Aquí se incrementa debe desagotar el tambor mediante una bomba
   y comenzar a centrifugar a una velocidad alta. Si pulsamos el botón acabará el
   programa y volverá al estado de Standby.

*/

const byte PULSADOR = 3;

void setup() {

  pinMode(PULSADOR, INPUT);

}

void loop() {

  int estado = 1;

  switch (estado) {

    // Estado 1: Stand-By
    case 1:
      if (digitalRead(PULSADOR) == HIGH) {
        while (digitalRead(PULSADOR)) { // evitar rebotes
          delay(10);
        }
        estado = 2;
      }
      break;

    // Estado 2: Lavado
    case 2:
      if (digitalRead(PULSADOR) == HIGH) {
        while (digitalRead(PULSADOR)) { // evitar rebotes
          delay(10);
        }
        estado = 3;
      }
      break;

    case 3: // Centrifugado
      if (digitalRead(PULSADOR) == HIGH) {
        while (digitalRead(PULSADOR)) { // evitar rebotes
          delay(10);
        }
        estado = 3;
      }
      break;
  }

}
