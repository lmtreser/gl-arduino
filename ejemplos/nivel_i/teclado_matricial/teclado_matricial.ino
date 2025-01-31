/*
  Teclado Matricial
  Jueves 1 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/bJibHdMGKGh

*/

//Libreria Keypad
//Alexander Brevig - alexanderbrevig@gmail.com
#include <Keypad.h>

const byte FILAS = 4; //cuatro filas
const byte COLUMNAS = 4; //cuatro columnas

char tecla[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte filaPines[FILAS] = {5, 4, 3, 2}; //pines de las filas
byte columnaPines[COLUMNAS] = {9, 8, 7, 6}; //pines de las columnas

Keypad teclado = Keypad( makeKeymap(tecla), filaPines, columnaPines, FILAS, COLUMNAS);

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  
  char tecla = teclado.getKey();
  
  if (tecla){
    Serial.println(tecla);
  }
}
