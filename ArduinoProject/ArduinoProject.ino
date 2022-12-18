#include "SoilMoistureSensor.h"
#include "WaterPomp.h"
#include "Brightness.h"
#include "Photoresistor.h"

#define PIN_PHOTORES A1
#define PIN_SOILMOISTURE A0
#define PIN_WATERPOMP 2

Brightness *photoresistor;
SoilMoistureSensor *soilMoistureSensor;
WaterPomp *waterPomp;

void setup() {
  Serial.begin(9600);
  photoresistor = new Photoresistor(PIN_PHOTORES);
  soilMoistureSensor = new SoilMoistureSensor(PIN_SOILMOISTURE);
  waterPomp = new WaterPomp(PIN_WATERPOMP);
}

void loop() {
  Serial.println(soilMoistureSensor->getValue());
  waterPomp->activate();
  delay(500);
  waterPomp->deactivate();

  Serial.println(photoresistor->getBrightness());

  delay(500);
}
