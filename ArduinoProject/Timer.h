#ifndef __TIMER__
#define __TIMER__

/**
 * Definition of the class Timer.
*/
class Timer {
    
public:  
  /**
   * Public constructor.
  */
  Timer();
  /**
   * Sets the frequence of the timer.
   * @param freq, indicates the frequence of the timer.
  */
  void setupFreq(int freq);  
  /**
   * Sets the period in milliseconds of the timer.
   * @param period, the period of the timer.
  */
  void setupPeriod(int period); 
  /**
   * Puts the caller in a pending state waiting for the next tick.
   */ 
  void waitForNextTick();
};


#endif
