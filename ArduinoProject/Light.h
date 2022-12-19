#ifndef __LIGHT__
#define __LIGHT__

class Light
{
    public:
        virtual void switchOff();
        virtual void switchOn();
        virtual bool isSwitchedOn();
        virtual void setBrightness(int value);
        virtual int getBrightness();
};

#endif
