/* Serial String
    Recibir un string desde el monitor serie
    https://www.automatismos-mdq.com.ar
*/

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {

    // leo un string hasta que ingresa una nueva línea
    String str = Serial.readStringUntil('\n');
    int dato1 = str.toInt();      // convierto el string a entero
    float dato2 = str.toFloat();  // convierto el string a float

    // muestro los datos por la consola
    Serial.print("String: ");
    Serial.println(str);
    Serial.print("Entero: ");
    Serial.println(dato1);
    Serial.print("Float: ");
    Serial.println(dato2);

  }
}
