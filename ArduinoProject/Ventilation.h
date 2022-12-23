#ifndef __VENTILATION__
#define __VENTILATION__

/**
 * Representation of a ventilation system.
*/
class Ventilation
{
public:
    /**
     * Activate the ventilation system.
    */
    virtual void activate();

    /**
     * Deactivate the ventilation system.
    */
    virtual void deactivate();

    /**
     * Check if the ventilation system is currently active.
     * @return true if the ventilation system is active, false otherwise.
    */
    virtual bool isActive();
};

#endif