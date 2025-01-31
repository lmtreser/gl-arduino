/*
   Ejemplo de uso de entrada analógica
*/

int potenciometro;
float resultado;

void setup() {

  Serial.begin(9600);

}

void loop() {

  //Obtener la lectura del canal A0
  potenciometro = analogRead(A0);

  //Convertir a mV
  resultado = potenciometro * 4.88;

  //Mostrar mediante el terminal
  Serial.print("El valor de la entrada es: ");
  Serial.print(resultado);
  Serial.println("mV");

  delay(100);
}
