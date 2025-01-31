/*
   Contador regresivo
   Viernes 17 de diciembre de 2021
*/

const int retardo = 1000;  // Base de tiempo, 1 segundo

unsigned long tiempo = 0;  // Usado para calcular la base de tiempo
int cuenta = 900;          // Contador en segundos
int segundos = 60;

void setup() {

  Serial.begin(9600);
}

void loop() {

  // Evento cada 1 segundo
  if (millis() > (tiempo + retardo)) {
    tiempo = millis();
    cuenta--;
    segundos--;

    // Calculo de minutos, con sus decenas y unidades
    int minutos = cuenta / 60;
    int minDec = minutos / 10;
    int minUni = minutos % 10;

    // Calculo de segundos, con sus decenas y unidades
    int segDec = segundos / 10;
    int segUni = segundos % 10;
    if (segundos == 0) segundos = 60;

    // Mostrar datos en el terminal
    Serial.print(cuenta);
    Serial.print("\t");
    Serial.print(minDec);
    Serial.print(minUni);
    Serial.print(":");
    Serial.print(segDec);
    Serial.println(segUni);
  }

}
