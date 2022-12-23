#ifndef __PHOTORESISTOR__
#define __PHOTORESISTOR__

#define ADC_REF_VOLTAGE 5.0
#define MAX_ADC_READING 1023
#define REF_RESISTANCE 5000
#define LUX_CALC_SCALAR 12518931
#define LUX_CALC_EXPONENT -1.405

#include "Brightness.h"
#include "Arduino.h"

/**
 * Implementation of the Brightness class using a photoresistor sensor.
*/
class Photoresistor : public Brightness
{
public:
    Photoresistor(int pin);
    float getBrightness();

private:
    int pin;
};

#endif