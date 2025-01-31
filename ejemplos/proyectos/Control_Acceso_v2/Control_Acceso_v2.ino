/*
  Control de acceso con el módulo RFID GP8F-R2
  28 de octubre de 2021
  Automatismos Mar del Plata -- https://www.automatismos-mdq.com.ar
*/

#include <SoftwareSerial.h>

SoftwareSerial portSerial(10, 11); // RX, TX
const int ABIERTO = 3000;
const int CERRADURA = 12;
const int TAGS = 3; // Cantidad de llaves registradas
const int TRAMA = 14; // Cantidad de bytes a recibir
boolean tag_valido = false; // Bandera indicadora de tag valido

// Llaves cargadas en el sistema
char llaves [TAGS][TRAMA] = {
  {2, '1', '1', '0', '0', '9', '1', 'D', '4', '4', 'E', '\r', '\n', 3},
  {2, '6', 'D', '0', '0', '5', '0', 'A', 'B', '4', 'B', '\r', '\n', 3},
  {2, '1', '1', '0', '0', '9', '2', '8', '4', '4', '6', '\r', '\n', 3}
};

void setup() {
  pinMode (CERRADURA, OUTPUT);
  Serial.begin(9600);
  portSerial.begin(9600);
  Serial.println("Control de acceso con el módulo GP8F-R2");
}

void loop() {

  // Esperar por datos en el puerto serie
  if (portSerial.available() > 0) {

    // Buffer para almacenar la lectura de los tags
    char read_buffer[TRAMA];
    // Obtener los datos
    portSerial.readBytes(read_buffer, TRAMA);

    // Enviar por el terminal el contenido del buffer
    Serial.print("ID-Tag: ");
    for (int i = 1; i < (TRAMA - 2); i++) {
      Serial.print(read_buffer[i]);
    }

    // Recorrer cada uno de los tags registrados
    for (int i = 0; i < TAGS; i++) {

      // Recorrer los datos de cada tag
      for (int j = 0; j < TRAMA; j++) {
        if (read_buffer[j] != llaves[i][j]) {
          break;
        } else if (j == 13) {
          tag_valido = true;
        }
      }
    }

    // Informa por terminal si encontró un tag valido
    if (tag_valido == true) {
      Serial.println(" - Acceso PERMITIDO");
      digitalWrite(CERRADURA, HIGH);
      delay (ABIERTO);
      digitalWrite(CERRADURA, LOW);
      tag_valido = false;
    } else {
      Serial.println(" - Acceso DENEGADO");
    }
  }
}
