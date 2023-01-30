#ifndef __TEMPHUMIDITY__
#define __TEMPHUMIDITY__
/**
 * Representation of a generic temperature and humidity sensor.
*/
class TemperatureAndHumidity
{
public:
    /**
     * Get the actual environment temperature.
     * @return the detected temperature.
    */
    virtual float getTemperature();
    /**
     * Get the actual environment humidity.
     * @return the detected humidity.
     */
    virtual float getHumidity();
};

#endif