/* Mini curso de Arduino
   Octubre 2020 - Lucas Treser
   Ejemplo "Blink"
*/

// función setup
void setup(){
	pinMode(13, OUTPUT);	
}

// función loop
void loop(){
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
}