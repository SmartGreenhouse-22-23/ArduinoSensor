#include "WaterPomp.h"

/**
 * Implementation of the class WaterPomp.
*/
WaterPomp::WaterPomp(int pin){
    this->pin = pin;
    this->active = false;
    pinMode(pin, OUTPUT);
}

void WaterPomp::activate(){
    active = true;
    digitalWrite(pin, LOW);
}

void WaterPomp::deactivate(){
    active = false;
    digitalWrite(pin, HIGH);
}

bool WaterPomp::isActivated(){
    return active;
}
