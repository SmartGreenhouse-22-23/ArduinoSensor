#include "Brightness.h"
#include "Photoresistor.h"

#define PIN_PHOTORES A1

Brightness *photoresistor;

void setup() {
  Serial.begin(9600);
  photoresistor = new Photoresistor(PIN_PHOTORES);

}

void loop() {
  Serial.println(photoresistor->getBrightness());
  delay(500);
}
