#include "SoilMoistureSensor.h"

SoilMoistureSensor::SoilMoistureSensor(int pin){
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int SoilMoistureSensor::getValue(){
    return analogRead(pin);
}
