#include "Photoresistor.h"

Photoresistor::Photoresistor(int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

float Photoresistor::getBrightness() {
    int rawData = analogRead(this->pin); //lettura del valore del convertitore
    float resistorVoltage = (float)rawData / MAX_ADC_READING * ADC_REF_VOLTAGE; //conversione del valore letto in volt
    float ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage; //calcolo del valore della fotoresistenza
    float ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
    return LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT); //calcolo del valore di luminosità
}