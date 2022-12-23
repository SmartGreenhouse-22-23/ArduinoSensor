#ifndef __LIGHT__
#define __LIGHT__
/**
 * Representation of a generic Ligh
*/
class Light
{
    public:
        /**
         * Set off the led
         */
        virtual void switchOff();
        /**
         * Set on the led
         */
        virtual void switchOn();
        /**
         * Check if the led status is ON
         * @return the status of the led, if it is ON
         */
        virtual bool isSwitchedOn();
        /**
         * Set the brighess of the led to value
         * @param value the new brightness
         */
        virtual void setBrightness(int value);
        /**
         * Get the actual brightness of the led
         * @return the led brightness
         */
        virtual int getBrightness();
};

#endif
