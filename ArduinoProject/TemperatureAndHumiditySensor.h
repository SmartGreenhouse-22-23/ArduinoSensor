#ifndef __TEMPHUMIDITYSENSOR__
#define __TEMPHUMIDITYSENSOR__

#include <Arduino.h>
#include "TemperatureAndHumidity.h"

#include <dht_nonblocking.h>

/**
 * Implementation of an Environment represented through a Temperature and Humidity DHT sensor.
 */
class TemperatureAndHumiditySensor : public TemperatureAndHumidity
{

public:
    TemperatureAndHumiditySensor(uint8_t pin);

    float getTemperature();
    float getHumidity();

private:
    DHT_nonblocking dht_sensor;
    float temperature;
    float humidity;
};

#endif
