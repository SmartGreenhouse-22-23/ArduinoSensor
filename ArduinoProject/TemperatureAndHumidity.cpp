#include "TemperatureAndHumidity.h"

TemperatureAndHumidity::TemperatureAndHumidity(uint8_t pin) : dht_sensor(pin, DHT_TYPE_11)
{
}

float TemperatureAndHumidity::getTemperature()
{
    bool res;

    do
    {
        res = dht_sensor.measure(&this->temperature, &this->humidity);
    } while (!res);

    return this->temperature;
}

float TemperatureAndHumidity::getHumidity()
{
    bool res;
    do
    {
        res = dht_sensor.measure(&this->temperature, &this->humidity);
    } while (!res);
    return this->humidity;
}
