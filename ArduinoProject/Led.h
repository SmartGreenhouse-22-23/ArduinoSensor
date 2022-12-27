#ifndef __LED__
#define __LED__

#include "Light.h"
#include "Arduino.h"

/**
 * Implementation of Light representing a Led sensor.
*/
class Led : public Light
{
public:
    Led(uint8_t pin);
    void switchOn();
    void switchOff();
    void setBrightness(int value);
    bool isSwitchedOn();
    int getBrightness();

private:
    int pin;
    bool on;
    int brightness;
};

#endif
