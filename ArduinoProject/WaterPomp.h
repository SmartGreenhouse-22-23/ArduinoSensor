#ifndef __WATERPOMP__
#define __WATERPOMP__

#include "Arduino.h"

/**
 * Declaration of the WaterPomp class.
*/
class WaterPomp
{
public:
    /**
     * The public constructor.
     * @param pin the pin related to the water pomp.
    */
    WaterPomp(int pin);
    /**
     * Activate the irrigation system.
    */
    void activate();
    /**
     * Deactivate the irrigation system.
    */
    void deactivate();
    /**
     * Checks if the system is active.
     * @return true if the irrigation is active false otherwise.
    */
    bool isActivated();

private:
    int pin;
    bool active;
};

#endif
