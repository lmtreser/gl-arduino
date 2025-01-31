/*
    Ejemplo de uso de módulo RFID-RC522
    Agosto de 2022 - www.automatismos-mdq.com.ar
    Utiliza la librería MFRC522 by GithubCommunity
    https://github.com/miguelbalboa/rfid
*/

#include <SPI.h>
#include <MFRC522.h>

const int RST_PIN = 9;
const int SS_PIN = 10;
MFRC522 mfrc522(SS_PIN, RST_PIN);

//funcion para imprimir un array
void printArray(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Lectura del UID de una tarjeta");
}

void loop() {

  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.print(F("UID:"));
      printArray(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.println();
      mfrc522.PICC_HaltA(); //finaliza la lectura actual
    }
  }
  delay(250);
}
