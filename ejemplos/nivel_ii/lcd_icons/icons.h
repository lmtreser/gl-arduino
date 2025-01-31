//Flecha abajo
byte arrowUp[8] = {
  B00100, B00100, B00100, B00100, B00100, B11111, B01110, B00100
};

// Flecha arriba
byte arrowDown[8] = {
  B00100, B01110, B11111, B00100, B00100, B00100, B00100, B00100
};

// Flecha derecha
byte arrowRight[8] = {
  B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000
};

// Flecha izquierda
byte arrowLeft[8] = {
  B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000
};

// Humedad
byte hum[8] = {
  B00100, B00100, B01010, B01010, B10001, B10001, B10001, B01110
};

// Temperatura
byte temp[8] = {
  B00100, B01010, B01010, B01110, B01110, B11111, B11111, B01110
};

// Grados 1
byte degrees1[8] = {
  B00111, B00101, B00111, B00000, B00000, B00000, B00000, B00000
};

// Grados 2
byte degrees2[8] = {
  B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000
};

// Corazón
byte heart[8] = {
  B00000, B01010, B11111, B11111, B01110, B00100, B00000, B00000
};

// [
byte bracket1[8] = {
  B11000, B10000, B10000, B10000, B10000, B10000, B10000, B11000
};

// ]
byte bracket2[8] = {
  B00011, B00001, B00001, B00001, B00001, B00001, B00001, B00011
};

// Candado cerrado
byte lock[8] = {
  B00000, B01110, B10001, B10001, B11111, B11011, B11011, B11111
};

// Candado abierto
byte unlock[8] = {
  B00000, B01110, B10000, B10000, B11111, B11011, B11011, B11111
};

// Bateria vacía
byte battEmpty[8] = {
  B01110, B01010, B11011, B10001, B10001, B10001, B10001, B11111
};

// Bateria mitad
byte battHalf[8] = {
  B01110, B01010, B11011, B10001, B10001, B11111, B11111, B11111
};

// Bateria llena
byte battFull[8] = {
  B01110, B01110, B11111, B11111, B11111, B11111, B11111, B11111
};