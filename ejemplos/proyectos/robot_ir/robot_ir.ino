/* Robot didáctico reciclado

  Ejemplo de aplicación de comando mediante control
  remoto infrarrojos

  Hitachi Remote Controller RB-CX38:

  Tecla         HEX         DEC         UINT
  PROGRAM       0xFF807F    16744575    32895
  STOP          0xFFF00F    16773135    61455
  PLAY/PAUSE    0xFF28D7    16722135    10455
  B.SKIP        0xFF10EF    16716015    4335
  F.SKIP        0xFFE01F    16769055    57375

  Librería
  https://github.com/Arduino-IRremote/Arduino-IRremote

  Detalles de construcción
  https://www.automatismos-mdq.com.ar/blog/2019/02/robot-didactico-con-materiales-reciclados.html
*/

#include <IRLib.h>

const int EN1 = 5;
const int IA1 = 12;
const int IB1 = 4;
const int IB2 = 8;
const int IA2 = 7;
const int EN2 = 6;
const int RECV_PIN = 2;

IRrecv My_Receiver(RECV_PIN);
IRdecode My_Decoder;

void setup() {

  // Pines del control de motores
  pinMode(IA1, OUTPUT);
  pinMode(IB1, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);

  // Inicializar motores
  analogWrite(EN1, 200);
  analogWrite(EN2, 200);
  digitalWrite(IA1, HIGH);
  digitalWrite(IB1, HIGH);
  digitalWrite(IA2, HIGH);
  digitalWrite(IB2, HIGH);

  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Inicia el receptor IR

}

void loop() {

  unsigned int tecla;

  // Lectura del sensor IR
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Receiver.resume();
    My_Decoder.decode();
    tecla = My_Decoder.value;
    Serial.print("Valor: ");
    Serial.println(tecla);
  }

  // De acuerdo a la tecla presionada, realizar una acción
  switch (tecla) {

    // Retroceder
    case 32895:
      Serial.println("Tecla PROGRAM");
      digitalWrite(IA1, HIGH);
      digitalWrite(IB1, LOW);
      digitalWrite(IA2, LOW);
      digitalWrite(IB2, HIGH);
      break;
    // Detener
    case 61455:
      Serial.println("Tecla STOP");
      digitalWrite(IA1, HIGH);
      digitalWrite(IB1, HIGH);
      digitalWrite(IA2, HIGH);
      digitalWrite(IB2, HIGH);
      break;
    // Avanzar
    case 10455:
      Serial.println("Tecla PLAY/PAUSE");
      digitalWrite(IA1, LOW);
      digitalWrite(IB1, HIGH);
      digitalWrite(IA2, HIGH);
      digitalWrite(IB2, LOW);
      break;
    // Girar a la izquierda
    case 4335:
      Serial.println("Tecla B.SKIP");
      digitalWrite(IA1, HIGH);
      digitalWrite(IB1, LOW);
      digitalWrite(IA2, HIGH);
      digitalWrite(IB2, LOW);
      break;
    // Girar a la derecha
    case 57375:
      Serial.println("Tecla F.SKIP");
      digitalWrite(IA1, LOW);
      digitalWrite(IB1, HIGH);
      digitalWrite(IA2, LOW);
      digitalWrite(IB2, HIGH);
      break;
  }
  delay(10);
}
