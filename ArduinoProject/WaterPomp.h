#ifndef __WATERPOMP__
#define __WATERPOMP__

#include "Arduino.h"

class WaterPomp
{
public:
    WaterPomp(int pin);
    void activate();
    void deactivate();
    bool isActivated();

private:
    int pin;
    bool active;
};

#endif
