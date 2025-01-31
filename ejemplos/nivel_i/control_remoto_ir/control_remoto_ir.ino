/*
  Utilizando un control remoto por infrarrojos
  Domingo 4 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/3AQTaQ43i1w

*/

//librería IR Remote
#include <IRremote.h>

const int LED_ROJO = 7;
const int LED_VERDE = 4;
const int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);
decode_results resultado;

void setup() {

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  Serial.begin(9600);
  Serial.println("Habilitando IR");
  irrecv.enableIRIn();
  Serial.println("IR habilitado");
}

void loop() {

  //irrecv.decode() retorna "true" si hay recepción
  //y almacena el dato en la variable "resultado"
  if (irrecv.decode(&resultado)) {
    unsigned int comando = resultado.value;
    Serial.println(comando);

    switch (comando) {
      case 2295: //tecla 1
        digitalWrite(LED_ROJO, HIGH);
        break;
      case 34935: //tecla 2
        digitalWrite(LED_VERDE, HIGH);
        break;
      case 255: //tecla on/off
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, LOW);
        break;
    }

    irrecv.resume(); //listo para recibir el próximo comando
  }
}
