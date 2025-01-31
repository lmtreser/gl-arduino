/*
  Display de 7 Segmentos (ánodo común)
  Domingo 4 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/94IGQ8CZsom

*/

//tabla de digitos ánodo común
byte  digito[10][8] = {
  { 0, 0, 0, 0, 0, 0, 1, 1 }, //0
  { 1, 0, 0, 1, 1, 1, 1, 1 }, //1
  { 0, 0, 1, 0, 0, 1, 0, 1 }, //2
  { 0, 0, 0, 0, 1, 1, 0, 1 }, //3
  { 1, 0, 0, 1, 1, 0, 0, 1 }, //4
  { 0, 1, 0, 0, 1, 0, 0, 1 }, //5
  { 0, 1, 0, 0, 0, 0, 0, 1 }, //6
  { 0, 0, 0, 1, 1, 1, 1, 1 }, //7
  { 0, 0, 0, 0, 0, 0, 0, 1 }, //8
  { 0, 0, 0, 1, 1, 0, 0, 1 }  //9
};

void setup() {

  //todos los pines como salidas
  for (int pines = 2; pines < 9; pines++) {
    pinMode(pines, OUTPUT);
  }
}

void loop() {

  //recorrer todos los digitos
  for (int i = 0; i < 10; i++) {
    visualizar(i);
    delay(1000);
  }

}

//función para "dibujar" los números
void visualizar(int numero) {

  for (int j = 0 ; j < 8 ; j++) {
    int valor = digito[numero][j] ;
    int pin = j + 2;
    digitalWrite(pin, valor) ;
  }
}
