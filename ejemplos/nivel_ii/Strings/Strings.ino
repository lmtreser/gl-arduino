/*
    Uso de Strings - Martes 21 de junio de 2022

    https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
    https://hetpro-store.com/TUTORIALES/arduino-string/

    String stringOne = "Hello String";                    // using a constant String
    String stringOne = String('a');                       // converting a constant char into a String
    String stringTwo = String("This is a string");        // converting a constant string into a String object
    String stringOne = String(stringTwo + " with more");  // concatenating two strings
    String stringOne = String(13);                        // using a constant integer
    String stringOne = String(analogRead(0), DEC);        // using an int and a base
    String stringOne = String(45, HEX);                   // using an int and a base (hexadecimal)
    String stringOne = String(255, BIN);                  // using an int and a base (binary)
    String stringOne = String(millis(), DEC);             // using a long and a base
    String stringOne = String(5.698, 3);                  // using a float and the decimal places

*/

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    // Concatenar un objeto string con una variable entera (convertida a String)
    String datos = "2305202" + String(i);
    unsigned long arreglo[5];
    
    // Conversión de un objeto String a entero para almacenarlo en un array
    arreglo [i] = datos.toInt();
    Serial.println(arreglo[i]);
  }
}

void loop() {

}
