#ifndef __HUMIDITY__
#define __HUMIDITY__
/**
 * Representation of greenhouse humidity.
 */
class Humidity
{
public:
    /**
     * Get the actual environment humidity.
     * @return the detected humidity.
     */
    virtual float getHumidity();
};

#endif