#ifndef __VENTILATION__
#define __VENTILATION__

class Ventilation
{
public:
    virtual void activate();
    virtual void deactivate();
    virtual bool isActive();
};

#endif