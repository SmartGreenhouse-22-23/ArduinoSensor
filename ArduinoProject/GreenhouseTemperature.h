#ifndef __GREENHOUSETEMPERATURE__
#define __GREENHOUSETEMPERATURE__
/**
 * Representation of greenhouse temperature.
 */
class GreenhouseTemperature
{
public:
    /**
     * Get the actual environment temperature.
     * @return the detected temperature.
     */
    virtual float getTemperature();
};

#endif