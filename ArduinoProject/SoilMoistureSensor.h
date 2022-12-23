#ifndef __SOILMOISTURE__
#define __SOILMOISTURE__

#include "Arduino.h"

/**
 * Definition of the class SoilMoistureSensor.
*/
class SoilMoistureSensor
{
public:
    /**
     * The public constructor.
     * @param pin the pin of the sensor.
    */
    SoilMoistureSensor(int pin);
    /**
     * Return the value detected.
    */
    int getValue();

private:
    int pin;
};

#endif
