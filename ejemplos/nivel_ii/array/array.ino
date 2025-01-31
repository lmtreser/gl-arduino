/*
  ARREGLO DE DATOS
  Martes 3 de mayo de 2022

  Un array es una colección de variables a las que se accede con un número de índice.
  https://www.arduino.cc/reference/en/language/variables/data-types/array/

*/

// Declarar un arreglo de datos
int arreglo[6];
int pines[] = {2, 4, 8, 3, 6};
int sensor[5] = {2, 4, -8, 3, 2};
char mensaje[6] = "hola!";

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Recorrer un arreglo de datos y mostrar el contenido
  for (byte i = 0; i < 5; i++) {
    Serial.print("Indice: [");
    Serial.print(i);
    Serial.print("]  ");
    Serial.print("Valor: ");
    Serial.println(mensaje[i]);
  }

  // Con fines de simulación
  Serial.println(" ---- ");
  delay(1000);

}
