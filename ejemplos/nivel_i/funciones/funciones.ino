/*
  Funciones de usuario
  Lunes 5 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/jFUYvWRWWE4

*/

//constantes
const int LED = 10;
const int POTENCIOMETRO = A0;

//variables
unsigned long tiempoActual = 0;
int tiempo = 0;
boolean ledEstado;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  tiempo = miFuncion();
  Serial.print("La funcion retorna: ");
  Serial.println(tiempo);

  //retardo no bloqueante
  if (millis() > (tiempoActual + tiempo)) {
    tiempoActual = millis();
    ledEstado = !ledEstado;
    digitalWrite(LED, ledEstado);
  }


}

//función para variar la velocidad de destellos
int miFuncion() {
  int valor = analogRead(POTENCIOMETRO);
  int destello = map(valor, 0, 1023, 100, 2000);
  return destello;
}
