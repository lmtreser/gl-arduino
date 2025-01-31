/*
  Control de flujo
  30 de septiembre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/eU7aWXee5qn

*/

// Constantes para las llaves
const int LLAVE_1 = 2;
const int LLAVE_2 = 3;
const int LLAVE_3 = 4;
const int LLAVE_4 = 5;

// Constantes para los LEDs
const int LED_ROJO = 13;
const int LED_VERDE = 12;
const int LED_AMARILLO = 11;
const int LED_AZUL = 10;

void setup() {

  // Configuración de entradas
  pinMode(LLAVE_1, INPUT);
  pinMode(LLAVE_2, INPUT);
  pinMode(LLAVE_3, INPUT);
  pinMode(LLAVE_4, INPUT);

  // Configuración de salidas
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  // DESCOMENTAR EL BLOQUE QUE SE DESEA PROBAR

  /*
    Serial.print("Estado llave1: ");
    Serial.println(digitalRead(LLAVE_1));
    Serial.print("Estado llave2: ");
    Serial.println(digitalRead(LLAVE_2));
    Serial.print("Estado llave3: ");
    Serial.println(digitalRead(LLAVE_3));
    Serial.print("Estado llave4: ");
    Serial.println(digitalRead(LLAVE_4));
  */

  /*
    if (digitalRead(LLAVE_1) == HIGH) {
    digitalWrite(LED_ROJO, HIGH);
    }
    else if (digitalRead(LLAVE_2) == HIGH &&
           digitalRead(LLAVE_3) == HIGH) {
    digitalWrite(LED_AZUL, HIGH);
    }
    else {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AZUL, LOW);
    }
  */

  /*
    switch (digitalRead(LLAVE_1)) {
    case 0:
      Serial.println("Caso nro. 1");
      break;
    case 1:
      Serial.println("Caso nro. 2");
      break;
    }
  */

  /*
    for (int contador = 0; contador < 20; contador++) {
    Serial.print(contador);
    }
  */

  /*
    while (digitalRead(LLAVE_1) == HIGH) {
    digitalWrite(LED_VERDE, HIGH);
    delay(500);
    digitalWrite(LED_VERDE, LOW);
    delay(500);
    }
  */

  /*
  int x = 0;
  do {
    x++;
    Serial.println(x);
  } while (digitalRead(LLAVE_1) == HIGH);
  */

  delay(10); // sólo para simulación
}
