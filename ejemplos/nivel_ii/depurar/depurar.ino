/*
   Depurar un programa con Serial.print
*/


// Activar o desactivar la depuración (true o false)
#define DEBUG true
#define Serial if(DEBUG)Serial

// Variables usadas en el ejemplo
float operadorA = 5.2;
float operadorB = 3.7;
float resultado;

void setup() {

  Serial.begin(9600);

}

void loop() {

  resultado = operadorA + operadorB;

  // Imprimir los datos
  Serial.println("Operador A: " + (String)operadorA + " - Operador B: "
                 + (String)operadorB + " - Resultado: " + (String)resultado);

  // Imprimir la cantidad de decimales deseada
  Serial.println(resultado, 2);
  delay(1000);

}
