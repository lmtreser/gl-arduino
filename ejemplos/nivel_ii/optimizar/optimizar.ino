/*
   Optimización del uso de memoria

*/

// Utilizar PROGMEM para guardar variables
const char miProgmem[] PROGMEM = {"Hola Mundo"};

void setup() {

  Serial.begin(9600);

  // 1. Evitar uso de strings, usar char array
  String miString = "Hola Mundo";
  char miChar [] = "Hola Mundo";
  Serial.println("Ejemplo #1");
  Serial.print("String: ");
  Serial.print(miString);
  Serial.print(" | Char: ");
  Serial.println(miChar);
  Serial.println();

  // 2. Utilizar PROGMEM para guardar variables en la memoria de
  // .. programación en lugar de la SRAM
  // .. const dataType variableName[] PROGMEM = {};
  // .. https://www.arduino.cc/reference/en/language/variables/utilities/progmem/
  unsigned int mensaje;
  char otroMensaje;

  // Lee enteros de 2 bytes y los muestra
  Serial.println("Ejemplo #2");
  Serial.println("Bucle para leer un array de enteros:");
  for (byte i = 0; i < 5; i++) {
    mensaje = pgm_read_word_near(miProgmem + i);
    Serial.println(mensaje);
  }
  Serial.println();

  // Leer caracteres y mostrarlos
  Serial.println("Bucle para leer un array de char: ");
  for (byte i = 0; i < strlen_P(miProgmem); i++) {
    otroMensaje = pgm_read_byte_near(miProgmem + i);
    Serial.print(otroMensaje);
  }
  Serial.println();
  Serial.println();

  // 3. Utilizar la función F con cada texto en formato
  // .. String para indicar que lo guarde en la memoria de programación
  Serial.println("Ejemplo #3");
  Serial.println(F("Uso de la función F"));
  Serial.println();

  // 4. Agrupar booleanos en un byte
  // .. Ejemplo con 8 LEDs y su estado, con este método
  // .. se utilizan 8 booleans, es decir 8 bytes
  bool led1 = true;
  bool led2 = true;
  bool led3 = false;
  bool led4 = true;
  bool led5 = false;
  bool led6 = false;
  bool led7 = true;
  bool led8 = true;
  // Se puede realizar con sólo un byte
  byte leds = 0b11010011;

  // Recuperar bits con la función bitRead
  Serial.println("Ejemplo #4");
  if (bitRead(leds, 0)) {
    Serial.println("El LED #1 está encendido");
  } else {
    Serial.println("El LED #1 está apagado");
  }

  // Cambiar bits con la función bitWrite
  bitWrite(leds, 0, 0);
  if (bitRead(leds, 0)) {
    Serial.println("El LED #1 está encendido");
  } else {
    Serial.println("El LED #1 está apagado");
  }
  Serial.println();

}

void loop() {

}
