/*   Timestamp mediante millis() v2 -- 21/06/2022
     Creación de una estampa de tiempo (timestamp) mediante el
     uso de la función millis() y funciones de usuarios.
*/

//constantes (segundos)
const int PERIODO = 1000;
const int EVENTO = 7;

//variables
unsigned long tiempoActual = 0;
boolean estado = true;
int t_year = 2022;
int t_month = 6;
int t_day = 18;
int t_hour = 18;
int t_minute = 3;
int t_second = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //rutina que se ejecuta cada cierto PERIODO de tiempo
  if (millis() >= (tiempoActual + PERIODO)) {

    toogle(); //cambia el estado del LED 13
    tiempoActual = millis(); //actualiza el tiempo actual
    t_second++;

    if (t_second > 59) {
      t_second = 0; //reinicia el segundero
      t_minute++; //incrementa minutero
    }

    if (t_minute > 59) {
      t_minute = 0; //reinicia el minutero
      t_hour++; //incrementa horas
    }

    //despues de transcurrido el tiempo, se origina un EVENTO
    if (t_second == EVENTO) {
      Serial.print(stampFecha());
      Serial.print(" - ");
      Serial.println(stampHora());
    }
  }
}

//funcion que genera un timestamp para la fecha
unsigned long stampFecha() {
  unsigned long fecha = t_day * 1000000UL + t_month * 10000UL + t_year;
  return fecha;
}

//funcion que genera un timestamp para la hora
unsigned long stampHora() {
  unsigned long hora = t_hour * 10000UL+ t_minute * 100 + t_second;
  return hora;
}

//funcion que genera un toogle en un LED
void toogle() {
  estado = !estado;
  digitalWrite(LED_BUILTIN, estado);
}
