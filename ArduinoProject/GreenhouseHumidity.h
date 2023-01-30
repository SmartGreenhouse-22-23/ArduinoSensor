#ifndef __GREENHOUSEHUMIDITY__
#define __GREENHOUSEHUMIDITY__
/**
 * Representation of greenhouse humidity.
 */
class GreenhouseHumidity
{
public:
    /**
     * Get the actual environment humidity.
     * @return the detected humidity.
     */
    virtual float getHumidity();
};

#endif