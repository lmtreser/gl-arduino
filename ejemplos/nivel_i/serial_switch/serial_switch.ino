/* Serial Switch
 *  Ejemplo de recepción de comandos mediante el monitor serie
 *  Uso de la estructura Switch Case para armar un menú de usuario 
 *  https://www.automatismos-mdq.com.ar
*/

void setup() {

  Serial.begin(9600);
  Serial.println("Bienvenido al sistema automático");
}

void loop() {

  int temperatura = 32; // leo el sensor de temperatura

  if (Serial.available() > 0) {

    char incomingByte = Serial.read(); // leer el byte ingresante

    switch (incomingByte) { // estructura de selección

      case 't':
        Serial.print("La temperatura ambiente es de: ");
        Serial.print(temperatura);
        Serial.println(" °C");
        break;

      case 'c':
        Serial.println("Menu de configuración");
        break;

      case 49: // el 49 es el número 1 en ASCII
        Serial.println("Opción Nro. 1");
        break;

      case '2':
        Serial.println("Opción Nro. 2");
        break;

      default:
        Serial.println("La opción ingresada no es correcta");
        break;
    }
  }
}
