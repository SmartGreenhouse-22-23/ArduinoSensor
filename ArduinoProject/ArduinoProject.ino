#include "SoilMoistureSensor.h"
#include "WaterPomp.h"

#define PIN_SOILMOISTURE A0
#define PIN_WATERPOMP 2

SoilMoistureSensor *soilMoistureSensor;
WaterPomp *waterPomp;

void setup() {
  Serial.begin(9600);
  soilMoistureSensor = new SoilMoistureSensor(PIN_SOILMOISTURE);
  waterPomp = new WaterPomp(PIN_WATERPOMP);
}

void loop() {
  Serial.println(soilMoistureSensor->getValue());
  waterPomp->activate();
  delay(500);
  waterPomp->deactivate();
  delay(500);
}
