/*  Media móvil exponencial

    La media básica es un poco imprecisa y vulnerable a picos en las mediciones,
    depende de hacer muchas mediciones para sacar una media más precisa. Es posible
    utilizar la media móvil exponencial, cuya fórmula es:

    media = (alfa * medición2) + ((1 - alfa) * medida1)

    Donde alfa es un número float entre 0 y 1, siendo lo más usado 0,05 o 0,1.
    En sintesis lo que se hace es tomar la nueva medición (medición2) y multiplicarla
    por alfa, es decir que sacamos un porcentaje (0,05 = 5%). Luego se suma esa
    cantidad al porcentaje restante (1 – 0,05 = 0,95 = 95%) de la medición antigua
    (medición1). Con esto se consegue que sólo una parte de la medición nueva afecte
    al resultado final, y por supuesto, cuanto más alto sea alfa, más afectará.
    Normalmente como medición antigua utilizamos la media básica.

    Por ejemplo:

    media = (220 * 0,05) + ((1 - 0,05) * 123) = 127,85
    media = (125 * 0,05) + ((1 - 0,05) * 127,85) = 127,70
    media = (121 * 0,05) + ((1 - 0,05) * 127,70) = 127,37 -> INT -> 127

    Resumiendo, el alfa controla cómo de estable es la media. Cuanto más alto sea alfa,
    más fluctuará, por lo que dependiendo del uso se puede ajustar. Por ejemplo,
    para un higrómetro o un termómetro nos vendrá bien que este número sea bajo porque
    su variación es lenta y muy baja, pero para otros casos como por ejemplo medir el
    voltaje de algo conectado nos puede venir mejor subirlo para detectar los cambios
    antes.

    https://www.electrosoftcloud.com/mejorar-las-lecturas-analogicas-de-tu-arduino-parte-2/

*/

const int SENSOR = A0;

void setup() {

  Serial.begin(9600);

}

void loop() {

  int lecturas[10];
  float alfa = 0.1;

  // Llenamos el array con números aleatorios, sólo con fines de simulación
  for (byte i = 0; i < 10; i++) {
    lecturas[i] = random(50, 60);
    Serial.println(lecturas[i]);
  }

  // Sacamos la primera media entre los dos primeros números
  float media = (alfa * lecturas[1]) + ((1 - alfa) * lecturas[0]);

  // Realizamos la media móvil exponencial usando el resto de números
  for (byte i = 0; i < 10; i++) {
    media = (alfa * lecturas[i]) + ((1 - alfa) * media);
  }

  Serial.print("La media móvil exponencial es:");
  Serial.println(media);

  delay(5000); // Sólo a fines de simulación

}
