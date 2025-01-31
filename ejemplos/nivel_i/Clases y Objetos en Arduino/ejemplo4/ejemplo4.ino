#include "Contador.h"

Contador C1, C2, C3 ;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(C1.Num_Objetos());
  Serial.flush();   
  exit(0);
}
