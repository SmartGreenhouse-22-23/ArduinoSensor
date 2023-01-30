#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(TemperatureAndHumidity *temphum)
{
   this->temphum = temphum;
}

float TemperatureSensor::getTemperature()
{
    return this->temphum->getTemperature();
}
