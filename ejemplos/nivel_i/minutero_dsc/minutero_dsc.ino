/*
   MINUTERO DESCENDENTE
   Contador de tiempo
   Sábado 4 de diciembre de 2021
*/

int segundero = 60;
int minutero = 14;
unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {

  // Evento cada 1 segundo
  if (millis() > (tiempo + 1000)) {
    tiempo = millis();
    segundero--;
    Serial.print(minutero);
    Serial.print(":");
    Serial.println(segundero);
  }

  // Decrementar minutos
  if (segundero == 0) {
    segundero = 60;
    minutero--;
  }

}
