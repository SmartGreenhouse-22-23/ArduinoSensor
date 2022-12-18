#include "SoilMoistureSensor.h"

#define PIN_SOILMOISTURE A0

SoilMoistureSensor *soilMoistureSensor;

void setup() {
  Serial.begin(9600);
  soilMoistureSensor = new SoilMoistureSensor(PIN_SOILMOISTURE);

}

void loop() {
  Serial.println(soilMoistureSensor->getValue());
  delay(500);
}
