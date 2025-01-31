/*
  ARREGLO DE DATOS DE DOS O MÁS DIMENSIONES
  Martes 3 de mayo de 2022

  Un arreglo (o matriz) con dos dimensiones es una representación de tablas de valores,
  organizadas en filas y columnas.
  Para identificar un elemento en particular, debemos especificar dos subíndices: el
  primero identifica la fila y el segundo la columna del elemento.
  Los arreglos que requieren de dos subíndices para identificar un elemento en particular
  se denominan matrices bidimensionales (2D). Los arreglos con dos o más dimensiones se
  conocen como matrices multidimensionales, el siguiente ejemplo muestra un arreglo 3x3:

          COLUMN 0    COLUMN 1    COLUMN 2
  ROW 0   a[0][0]     a[0][1]     a[0][2]
  ROW 1   a[1][0]     a[1][1]     a[1][2]
  ROW 2   a[2][0]     a[2][1]     a[2][2]

*/

// Constantes
const int rows = 3;
const int columns = 3;

// Declarar un arreglo de datos multidimensional
char matrix[rows][columns] = {
  { 'a', 'b', 'c' },
  { 'd', 'e', 'f' },
  { 'g', 'h', 'i' }
};

void setup() {
  Serial.begin(9600);
}

void loop() {

  for (byte i = 0; i < rows; i++) { // Recorrer las filas

    for (byte j = 0; j < columns; j++) { // Recorrer las columnas
      Serial.print("Fila: [");
      Serial.print(i);
      Serial.print("]  ");
      Serial.print("Columna: [");
      Serial.print(j);
      Serial.print("]  ");
      Serial.print("Valor: ");
      Serial.println(matrix[i][j]);
    }

  }

  // Con fines de simulación
  Serial.println(" ---- ");
  delay(1000);

}
