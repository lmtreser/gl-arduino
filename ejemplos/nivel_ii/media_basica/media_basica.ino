/*
    MEDIA BÁSICA
    La media básica es un método para sacar la media de una serie de números.
    Simplemente se suma X números, y divide el total entre la cantidad de números.
    Mientras menos números se utilicen, más baja será su precisión.

    La fórmula es la siguiente: media = (n1 + n2 + n3 + n4) / 4

    Por ejemplo, si tenemos 4 mediciones analógicas, y una de ellas (n3) sufre
    una interferencia y recibimos un pico durante la medición, el resultado será:

    media = (123 + 125 + 220 + 121 ) / 4 = ~147

    El mismo ejemplo pero usando más cantidad de muestras (10) atenuará el pico:

    media = (123 + 125 + 220 + 121 + 120 + 127 + 123 + 121 + 125 + 120) / 10 = ~132

    https://www.electrosoftcloud.com/mejorar-las-lecturas-analogicas-de-tu-arduino-parte-2/

*/

const byte SENSOR = A0;

void setup() {

  Serial.begin(9600);

}

void loop() {

  int lecturas[10];
  int suma, media;

  Serial.print("Lecturas: ");
  for (byte i = 0; i < 10; i++) {
    lecturas[i] = analogRead(SENSOR);
    suma += lecturas[i];
    Serial.print(lecturas[i]);
    Serial.print(", ");
    delay(10);
  }

  media = suma / 10;
  Serial.println();
  Serial.print("La media de la lectura es: ");
  Serial.println(media);

  delay(1000);
}
