/*
  Funciones útiles
  Martes 13 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/53W4nz91loD

*/

const int BUZZER = 3;
const int POTENCIOMETRO = A0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  /*
    //función min()
    Serial.print("Devuelve el minimo de dos numeros: ");
    Serial.println(min(5,1));
  */

  /*
    //función max()
    Serial.print("Devuelve el maximo de dos numeros: ");
    Serial.println(max(8,2));
  */

  /*
    //función map()
    int valorInicial = analogRead(POTENCIOMETRO);
    int valorFinal = map(valorInicial, 0, 1023, 0, 255);
    Serial.print("Valor inicial: ");
    Serial.print(valorInicial);
    Serial.print(" | Valor final: ");
    Serial.println(valorFinal);
  */

  /*
    //función random()
    Serial.println(random(0,1000));
  */

  /*
    //función tone()
    tone(BUZZER, 300);
    //tone(BUZZER, 300, 100);
    delay(1000);
  */
}
