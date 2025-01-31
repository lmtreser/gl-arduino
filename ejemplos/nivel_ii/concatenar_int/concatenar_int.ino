/*
    CONCATENAR VARIABLES DE TIPO INT
    Es posible concatenar variables de tipo entero, por ejemplo de
    la siguiente manera:

    int n1=1, n2=2, n3=3;
    int num = n1*100 + n2*10 + n3;

    UNSIGNED LONG --> 32 bits --> 4 bytes --> 0 to 4,294,967,295
    https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/

    A tener en cuenta, hay que convertir las constantes multiplicadoras al tipo de
    datos adecuado ya que puede ocasionar problemas:
    https://forum.arduino.cc/t/why-am-i-getting-this-multiplication-error/41500/2

    Conversion a unsigned long:
    https://www.arduino.cc/reference/en/language/variables/conversion/unsignedlongcast/

    Integer Constants:
    https://www.arduino.cc/reference/en/language/variables/constants/integerconstants/
*/

// Variables a concatenar
int t_year = 2022;
int t_month = 12;
int t_day = 31;
int t_hour = 23;
int t_minute = 59;
int t_second = 59;

void setup() {

  Serial.begin(9600);

  // Para obtener algo así como DDMMYYYY usando una variable unsigned long
  // -- 31 de diciembre de 2022
  unsigned long fecha = (t_day * 1000000UL) + (t_month * 10000UL) + t_year;
  // Para obtener algo así como HHMMSS usando una variable unsigned long
  // -- 23:59:59
  unsigned long hora = (t_hour * 10000UL) + (t_minute * 100) + t_second;
  Serial.print("Timestamp #1: ");
  Serial.print(fecha);
  Serial.print(" - ");
  Serial.println(hora);

  // Cambian los valores
  t_year = 2022;
  t_month = 6;
  t_day = 21;
  t_hour = 19;
  t_minute = 37;
  t_second = 43;

  // Para obtener algo así como DDMMYYYY usando una variable unsigned long
  // -- 21 de junio de 2022
  fecha = (t_day * (unsigned long)1000000) + (t_month * (unsigned long)10000) + t_year;
  // Para obtener algo así como HHMMSS usando una variable unsigned long
  // -- 19:37:43
  hora = (t_hour * (unsigned long)10000) + (t_minute * 100) + t_second;
  Serial.print("Timestamp #2: ");
  Serial.print(fecha);
  Serial.print(" - ");
  Serial.println(hora);

}

void loop() {

}
