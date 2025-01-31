/*
  Tira de NeoPixeles
  Viernes 2 de octubre 2020

  Lucas Martín Treser - Automatismos Mar del Plata
  https://www.automatismos-mdq.com.ar/

  Simulación en:
  https://www.tinkercad.com/things/b6gOKOYS9qq

*/

//Librería AdaFruit NeoPixel
#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 4
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int retardo = 100;

void setup() {
  pixels.begin(); //inicia la librería NeoPixel
}

void loop() {

  for (int i = 0; i < NUMPIXELS; i++) {

    //pixels.Color usa valores RGB: desde 0,0,0 hasta 255,255,255
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 255, 255));

    pixels.show(); //actualiza el color del pixel
    delay(retardo);

  }

}
