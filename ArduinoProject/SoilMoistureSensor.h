#ifndef __SOILMOISTURE__
#define __SOILMOISTURE__

#include "Arduino.h"

class SoilMoistureSensor
{
public:
    SoilMoistureSensor(int pin);
    int getValue();

private:
    int pin;
};

#endif
