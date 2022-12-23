#include "SoilMoistureSensor.h"

/** 
 * Implementation of the class SoilMoistureSensor.
*/
SoilMoistureSensor::SoilMoistureSensor(int pin){
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int SoilMoistureSensor::getValue(){
    return analogRead(pin);
}
