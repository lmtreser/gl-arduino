#include <Thread.h>

int ledPin = 13;
unsigned int x;

//My simple Thread
Thread myThread = Thread();
//Otro hilo
Thread Thread2 = Thread();

void mensaje() {
  Serial.println(x);
}

// callback for myThread
void niceCallback() {
  static bool ledStatus = false;
  ledStatus = !ledStatus;
  digitalWrite(ledPin, ledStatus);
  Serial.print("COOL! I'm running on: ");
  Serial.println(millis());
}

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  myThread.onRun(niceCallback);
  myThread.setInterval(500);

  Thread2.onRun(mensaje);
  Thread2.setInterval(1000);

}

void loop() {
  // checks if thread should run
  if (myThread.shouldRun())
    myThread.run();

  if (Thread2.shouldRun())
    Thread2.run();

  // Other code...
  x = x + 1;

}
