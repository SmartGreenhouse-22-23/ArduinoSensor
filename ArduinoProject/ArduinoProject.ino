#include "SoilMoistureSensor.h"
#include "WaterPomp.h"
#include "Brightness.h"
#include "Photoresistor.h"
#include "Ventilation.h"
#include "Fan.h"

#define PIN_PHOTORES A1
#define PIN_SOILMOISTURE A0
#define PIN_WATERPOMP 2
#define PIN_ENABLE 5
#define PIN_DIRA 6
#define PIN_DIRB 4

Ventilation *ventilation;
Brightness *photoresistor;
SoilMoistureSensor *soilMoistureSensor;
WaterPomp *waterPomp;


void setup() {
  Serial.begin(9600);
  ventilation = new Fan(PIN_ENABLE, PIN_DIRA, PIN_DIRB);
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

  if (ventilation->isActive()) {
    ventilation->deactivate();
  } else {
    ventilation->activate();
  }
  delay(2000);
}
