#include "Led.h"

Led::Led(uint8_t pin) {
    this->on = false;
    this->brightness = 255;
    this->pin = pin;
}

void Led::switchOn(){
    this->on = true;
    analogWrite(this->pin, this->brightness);
}

void Led::switchOff(){
    this->on = false;
    analogWrite(this->pin, 0);
}

void Led::setBrightness(int val){
    this->brightness = val;
    analogWrite(this->pin, this->brightness);
}


bool Led::isSwitchedOn(){
    return this->brightness > 0;
}

int Led::getBrightness(){
    return this->brightness;
}
