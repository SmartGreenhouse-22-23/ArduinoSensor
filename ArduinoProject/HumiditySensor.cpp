#include "HumiditySensor.h"

HumiditySensor::HumiditySensor(TemperatureAndHumidity *temphum)
{
   this->temphum = temphum;
}

float HumiditySensor::getHumidity()
{
   return this->temphum->getHumidity();
}
