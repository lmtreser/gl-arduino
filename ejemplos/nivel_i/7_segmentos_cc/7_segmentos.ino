/*
  Display de 7 Segmentos
  Sábado 3 de octubre de 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación disponible en:
  https://www.tinkercad.com/things/c2zyM72zDAK

*/

//tabla de digitos cátodo común
byte  digito[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0 }, //0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, //1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, //2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, //3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, //4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, //5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, //6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, //7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, //8
  { 1, 1, 1, 0, 0, 1, 1, 0 }  //9
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
