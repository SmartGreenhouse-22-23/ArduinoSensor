#ifndef __HUMIDITY__
#define __HUMIDITY__

#include <Arduino.h>
#include "GreenhouseHumidity.h"
#include "Environment.h"

#include <dht_nonblocking.h>
/**
 * Implementation of a greenhouse humidity.
 */
class Humidity : public GreenhouseHumidity
{
  Environment *env;

public:
    Humidity(Environment *env);
    float getHumidity();
};

#endif
