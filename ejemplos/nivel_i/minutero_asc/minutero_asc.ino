/*
   MINUTERO ASCENDENTE
   Contador de tiempo
   Sábado 4 de diciembre de 2021
*/

int segundero = 0;
int minutero = 0;
unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {

  // Evento cada 1 segundo
  if (millis() > (tiempo + 1000)) {
    tiempo = millis();
    segundero++;
    Serial.print(minutero);
    Serial.print(":");
    Serial.println(segundero);
  }

  // Incrementar minutos
  if (segundero == 59) {
    segundero = -1;
    minutero++;
  }

}
