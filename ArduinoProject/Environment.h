#ifndef __ENVIROMENT__
#define __ENVIROMENT__
/**
 * Representation of a generic environment.
*/
class Environment
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