/*
  Comunicación Módulo RFID GP8F-R2
  26 de octubre de 2021

  El módulo GP8F-R2 lee tarjetas o tags RFID read-only de 64-bits, código
  Manchester a 125KHz. Posee una salida para conectar un LED, que permanece
  encendido al aproximar un tag RFID. El ID correspondiente se entrega por un
  terminal en formato 8 bits serie asincrónico, a 9600 bps, sin paridad, a
  nivel lógico. El usuario puede optar por conectarlo a algun driver RS-232
  para leerlo desde una PC, o conectarlo directamente a un microcontrolador o
  UART. El formato lógico responde al siguiente esquema, en ASCII:

  <STX> <DATA (10 bytes)> <CR> <LF> <ETX>

  STX: ASCII Start of Text (02h)
  ETX: ASCII End of Text (03h)
  CR: ASCII Carriage Return (0Dh)
  LF: ASCII Line Feed (0Ah)

  El campo de DATA es una representación en ASCII del ID del RFID, representando
  5 bytes binarios (40 bits) de la siguiente forma:

  byte  ASCII
  C1    43 31

  Por ejemplo, el ID 60 22 57 C0 31 se transmite de la siguiente forma:

  02 36 30 32 32 35 37 43 30 33 31 0D 0A 03

  Recordemos que este tipo de RFID tags de 64 bits 125 Khz utiliza 9 bits para
  header, 40 para datos, 14 bits de paridad y uno de stop.

*/

#include <SoftwareSerial.h>

SoftwareSerial portSerial(10, 11); // RX, TX

const int TRAMA = 14; // Cantidad de bytes a recibir

/* Llaves cargadas en el sistema. El monitor serie de Arduino envia la información
   en codificación ASCII:

   2, '1', '1', '0', '0', '9', '1', 'D', '4', '4', 'E', '\r', '\n', 3

   También es posible usar el formato hexadecimal:

   0x02, 0x31, 0x31, 0x30, 0x30, 0x39, 0x31, 0x44, 0x34, 0x34, 0x45, 0x0D, 0x0A, 0x03

*/

// 110091D44E
char llavero1[TRAMA] = {0x02, 0x31, 0x31, 0x30, 0x30, 0x39, 0x31,
                        0x44, 0x34, 0x34, 0x45, 0x0D, 0x0A, 0x03
                       };
// 6D0050AB4B
char llavero2[TRAMA] = {2, '6', 'D', '0', '0', '5', '0', 'A', 'B',
                        '4', 'B', '\r', '\n', 3
                       };

// 1100928446
char llavero3[TRAMA] = {2, '1', '1', '0', '0', '9', '2', '8', '4',
                        '4', '6', '\r', '\n', 3
                       };

void setup() {

  Serial.begin(9600);
  portSerial.begin(9600);
  Serial.println("Módulo GP8F-R2");
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

    // Función que devuelve si un tag es válido
    for (int i = 0; i < TRAMA; i++) {
      if (read_buffer[i] != llavero1[i]) {
        Serial.println(" - Acceso DENEGADO");
        break;
      }
      if (i == 13) {
        Serial.println(" - Acceso PERMITIDO");
      }
    }
  }
}
