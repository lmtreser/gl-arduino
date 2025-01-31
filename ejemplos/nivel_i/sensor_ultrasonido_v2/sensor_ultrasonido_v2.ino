/*
  Sensor de distancia por ultrasonido
  Lunes 19 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/4m7g7P5vQ7M

  La velocidad del sonido es 343 m/s (a 20 ºC, 50% de humedad, presión
  atmosférica a nivel del mar), por lo tanto tarda 29,2 microsegundos
  en recorrer un centímetro. La siguiente fórmula permite calcular el
  tiempo entre ida y vuelta del sonido respecto al sensor:

  distancia (cm) = tiempo(µS) / 29.2µS * 2

*/

const int ECHO = 3;
const int TRIG = 2;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {

  int distancia = ping(TRIG, ECHO);
  Serial.print("Distancia en CM: ");
  Serial.println(distancia);
  delay(10);
}

//función ping
int ping(int triggerPin, int echoPin) {

  long duracion, distanciaCm;
  //para generar un pulso limpio ponemos a LOW 4µs
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(4);
  //generamos un disparo de 10µs
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  //medimos el tiempo entre pulsos
  duracion = pulseIn(echoPin, HIGH);
  //convertimos a distancia
  distanciaCm = duracion * 10 / 292 / 2;
  return distanciaCm;
}
