/*   Timestamp mediante millis() -- 18/06/2022
     Creación de una estampa de tiempo (timestamp) mediante el
     uso de la función millis(), funciones de usuarios y objeto
     de tipo String.
*/

//constantes (segundos)
const int PERIODO = 1000;
const int EVENTO = 50;

//variables
unsigned long tiempoActual = 0;
boolean estado = true;
int t_year = 2022;
int t_month = 6;
int t_day = 18;
int t_hour = 18;
int t_minute = 30;
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
      String mensaje;
      estampa(mensaje);
      Serial.println(mensaje);
    }
  }
}

//funcion que genera un timestamp
void estampa(String &estampaTemporal) {
  estampaTemporal = estampaTemporal + t_day + "/" + t_month + "/" + t_year
                    + " - " + t_hour + ":" + t_minute + ":" + t_second;
}

//funcion que genera un toogle en un LED
void toogle() {
  estado = !estado;
  digitalWrite(LED_BUILTIN, estado);
}
