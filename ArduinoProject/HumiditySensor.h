#ifndef __HUMIDITYSENSOR__
#define __HUMIDITYSENSOR__

#include <Arduino.h>
#include "Humidity.h"
#include "TemperatureAndHumidity.h"
/**
 * Implementation of a greenhouse humidity.
 */
class HumiditySensor : public Humidity
{
  TemperatureAndHumidity *temphum;

public:
  HumiditySensor(TemperatureAndHumidity *temphum);
  float getHumidity();
};

#endif
