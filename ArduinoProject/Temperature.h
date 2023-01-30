#ifndef __TEMPERATURE__
#define __TEMPERATURE__
/**
 * Representation of greenhouse temperature.
 */
class Temperature
{
public:
    /**
     * Get the actual environment temperature.
     * @return the detected temperature.
     */
    virtual float getTemperature();
};

#endif