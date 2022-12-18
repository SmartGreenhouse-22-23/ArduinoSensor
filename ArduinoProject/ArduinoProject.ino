#include "WaterPomp.h"

#define PIN_WATERPOMP 2

WaterPomp *waterPomp;

void setup() {
  waterPomp = new WaterPomp(PIN_WATERPOMP);
}

void loop() {
  waterPomp->activate();
  delay(500);
  waterPomp->deactivate();
  delay(500);
}
