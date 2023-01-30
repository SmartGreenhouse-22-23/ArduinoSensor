#include "TemperatureAndHumiditySensor.h"

TemperatureAndHumiditySensor::TemperatureAndHumiditySensor(uint8_t pin) : dht_sensor(pin, DHT_TYPE_11)
{
}

float TemperatureAndHumiditySensor::getTemperature()
{
    bool res;

    do
    {
        res = dht_sensor.measure(&this->temperature, &this->humidity);
    } while (!res);

    return this->temperature;
}

float TemperatureAndHumiditySensor::getHumidity()
{
    bool res;
    do
    {
        res = dht_sensor.measure(&this->temperature, &this->humidity);
    } while (!res);
    return this->humidity;
}
