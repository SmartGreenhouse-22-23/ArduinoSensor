#ifndef __TEMPERATURE__
#define __TEMPERATURE__

#include <Arduino.h>
#include "GreenhouseTemperature.h"
#include "Environment.h"

#include <dht_nonblocking.h>
/**
 * Implementation of a greenhouse temperature.
 */
class Temperature : public GreenhouseTemperature
{
  Environment *env;

public:
    Temperature(Environment *env); 
    float getTemperature();
};

#endif
