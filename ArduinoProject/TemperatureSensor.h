#ifndef __TEMPERATURESENSOR__
#define __TEMPERATURESENSOR__

#include <Arduino.h>
#include "Temperature.h"
#include "TemperatureAndHumidity.h"
/**
 * Implementation of a greenhouse temperature.
 */
class TemperatureSensor : public Temperature
{
  TemperatureAndHumidity *temphum;

public:
  TemperatureSensor(TemperatureAndHumidity *temphum);
  float getTemperature();
};

#endif
