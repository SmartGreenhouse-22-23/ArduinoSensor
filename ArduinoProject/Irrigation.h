#ifndef __IRRIGATION__
#define __IRRIGATION__

/**
 * Representation of a irrigation system.
*/
class Irrigation
{
public:
    /**
     * Activate the irrigation system.
    */
    virtual void activate();

    /**
     * Deactivate the irrigation system.
    */
    virtual void deactivate();

    /**
     * Check if the irrigation system is currently active.
     * @return true if the ventilation system is active, false otherwise.
    */
    virtual bool isActive();
};

#endif