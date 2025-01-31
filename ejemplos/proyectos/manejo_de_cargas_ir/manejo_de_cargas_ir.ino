/*
  Control de cargas mediante relé y control remoto
  Miércoles 7 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/iQJvZ5lYAAr

*/

//librería IR Remote
#include <IRremote.h>

//constantes
const int RECV_PIN = 11;
const int RELE_1 = 2;
const int RELE_2 = 3;

//configuración IR
IRrecv irrecv(RECV_PIN);
decode_results resultado;

void setup() {

  pinMode(RELE_1, OUTPUT);
  pinMode(RELE_2, OUTPUT);
  irrecv.enableIRIn();

}

void loop() {

  if (irrecv.decode(&resultado)) {
    unsigned int comando = resultado.value;

    switch (comando) {
      case 2295: //tecla 1
        digitalWrite(RELE_1, HIGH);
        break;
      case 34935: //tecla 2
        digitalWrite(RELE_2, HIGH);
        break;
      case 255: //tecla on/off
        digitalWrite(RELE_1, LOW);
        digitalWrite(RELE_2, LOW);
        break;
    }

    irrecv.resume(); //listo para recibir el próximo comando
  }

}
