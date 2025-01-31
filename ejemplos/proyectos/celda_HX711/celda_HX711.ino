/*
  Este código fue creado por Nathan Seidle de SparkFun Electronics y lo puedes encontrar en:
  https://github.com/sparkfun/HX711-Load-Cell-Amplifier/blob/master/firmware/SparkFun_HX711_Calibration/

  La librería está disponible en https://github.com/bogde/HX711
  El ejemplo está disponible en https://programarfacil.com/blog/arduino-blog/hx711-arduino-bascula-digital/

  Está sujeto a la licencia Beerware lo que viene a decir que el código es de dominio público. Si lo utilizas
  en algún proyecto te comprometes a invitar a una cerveza a Nathan Seidle si algún día te encuentras con el :)

  Este programa permite calibrar la báscula. Se utiliza para determinar el factor de calibración.
  También puede servir para generar el factor cero útil en básculas que tienen una masa permanente.

  Para empezar la configuración de la báscula tienes que iniciar este programa sin tener ningún peso encima
  de la báscula. Una vez empiecen a aparecer medidas de peso en el monitor serie, coloca algún objeto con un
  peso conocido sobre la báscula. Luego, en el monitor serie pon + o - (en símbolo) para ajustar el factor de
  calibración (factor_calibracion) hasta que la salida conincida con el peso conocido del objeto.

  Por ejemplo, puedes poner un kilo de arroz o un kilo de naranjas. Mi recomendación es que si tienes otro
  peso en casa primero lo peses en ese peso y así sabrás con exactitud cuanto pesa. Una vez el peso coincida
  apunta el valor del factor de calibración (factor_calibracion).

  Tu factor de calibración puede ser muy diferente al mío. Puede que sea muy positivo o muy negativo.
  Todo esto depende de la configuración de tu sistema de báscula, la célula de carga y los sensores de carga.
*/

#include "HX711.h"

// Pin de datos y de reloj
byte pinData = 3;
byte pinClk = 2;

HX711 bascula;

// Parámetro para calibrar el peso y el sensor
//Este valor del factor de calibración funciona para mi. El tuyo probablemente será diferente.
float factor_calibracion = 20450.0; 

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 programa de calibracion");
  Serial.println("Quita cualquier peso de la bascula");
  Serial.println("Una vez empiece a mostrar informacion de medidas, coloca un peso conocido encima de la bascula");
  Serial.println("Presiona + para incrementar el factor de calibracion");
  Serial.println("Presiona - para disminuir el factor de calibracion");

  // Iniciar sensor
  bascula.begin(pinData, pinClk);

  // Aplicar la calibración
  bascula.set_scale();
  // Iniciar la tara
  // No tiene que haber nada sobre el peso
  bascula.tare();

  // Obtener una lectura de referencia
  long zero_factor = bascula.read_average();
  // Mostrar la primera desviación
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
}

void loop() {

  // Aplicar calibración
  bascula.set_scale(factor_calibracion);

  // Mostrar la información para ajustar el factor de calibración
  Serial.print("Leyendo: ");
  float peso = bascula.get_units() * 10;
  Serial.print(peso, 1);
  Serial.print(" gramos");
  Serial.print(" factor_calibracion: ");
  Serial.print(factor_calibracion);
  Serial.println();

  // Obtener información desde el monitor serie
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == '+')
      factor_calibracion += 10;
    else if (temp == '-')
      factor_calibracion -= 10;
  }
}
