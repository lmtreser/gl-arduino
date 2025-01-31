/*
   ENCODER ROTATIVO CON SWITCH
   Tener en cuenta si se usan módulos (KY-040)
   con resistencias de pull-up en los pines del dispositivo.

   Martes 28 de diciembre de 2021
   https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
*/

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;

const byte CLK = 2;
const byte DT = 3;
const byte SW = 4;

void setup() {

  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT);

  Serial.begin(9600);

  // Leer el estado inicial de CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {

  // Leer el estado actual de CLK
  currentStateCLK = digitalRead(CLK);

  // Si el último y actual estado de CLK son diferentes
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {

    // Si el estado de DT es diferente al estado de CLK
    // Encoder girando en sentido CCW, decrementar
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir = "CCW";
    } else {
      // Encoder girando en sentido CW, incrementar
      counter ++;
      currentDir = "CW";
    }

    Serial.print("Dirección: ");
    Serial.print(currentDir);
    Serial.print(" | Contador: ");
    Serial.println(counter);
  }

  // Almacenar el último estado de CLK
  lastStateCLK = currentStateCLK;

  // Leer el estado del pulsador
  int btnState = digitalRead(SW);

  // Si se detecta una señal LOW, el botón fue presionado
  if (btnState == LOW) {
    // si pasaron 50ms desde el último estado LOW, significa 
    // que el se ha pulsado, soltado y pulsado de nuevo
    if (millis() - lastButtonPress > 50) {
      Serial.println("Botón presionado!");
    }

    // Almacenar el tiempo del último evento de botón
    lastButtonPress = millis();
  }

  delay(1);
}
