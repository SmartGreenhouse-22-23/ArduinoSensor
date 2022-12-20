#include "WaterPomp.h"

WaterPomp::WaterPomp(int pin){
    this->pin = pin;
    this->active = false;
    pinMode(pin, OUTPUT);
}

void WaterPomp::activate(){
    active = true;
    digitalWrite(pin, HIGH);
}

void WaterPomp::deactivate(){
    active = false;
    digitalWrite(pin, LOW);
}

bool WaterPomp::isActivated(){
    return active;
}
