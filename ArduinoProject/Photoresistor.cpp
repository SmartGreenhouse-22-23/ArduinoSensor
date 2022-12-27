#include "Photoresistor.h"

/**
 * Implementation of the Photoresistor class.
*/
Photoresistor::Photoresistor(int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

float Photoresistor::getBrightness() {
    int rawData = analogRead(this->pin); //read the value of the converter
    float resistorVoltage = (float)rawData / MAX_ADC_READING * ADC_REF_VOLTAGE; //conversion of the value read in volt
    float ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage; //calculation of the value of the photoresistance
    float ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
    return LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT); //calculation of the brightness value
}