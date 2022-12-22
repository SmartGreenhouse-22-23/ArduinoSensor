#ifndef __TASK__
#define __TASK__

#include "Arduino.h"
class Task
{

public:
  Task()
  {
  }

  virtual void init(unsigned long period)
  {
    myPeriod = period;
    timeElapsed = 0;
  }

  virtual void tick() = 0;

  bool updateAndCheckTime(unsigned long basePeriod)
  {
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod)
    {
      timeElapsed = 0;
      return true;
    }
    else
    {
      return false;
    }
  }

  virtual bool isActive();

  virtual void setActive(bool active);

private:
  unsigned long myPeriod;
  unsigned long timeElapsed;
  bool active;
};

#endif
