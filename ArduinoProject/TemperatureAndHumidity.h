#include <dht_nonblocking.h>

#ifndef __TEMPHUMIDITY__
#define __TEMPHUMIDITY__

#include <Arduino.h>
#include "Environment.h"

#include <dht_nonblocking.h>

class TemperatureAndHumidity : public Environment
{

public:
    TemperatureAndHumidity(uint8_t pin);

    float getTemperature();
    float getHumidity();

private:
    DHT_nonblocking dht_sensor;
    float temperature;
    float humidity;
};

#endif
