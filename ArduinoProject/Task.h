#ifndef __TASK__
#define __TASK__

#include "Arduino.h"
/**
 * Definition of interface Task.
*/
class Task
{

public:
  /**
   * Public empty constructor.
  */
  Task()
  {
  }
  /**
   * Initialize the task.
   * @param period the period of the task to be evaluated by the Scheduler.
  */
  virtual void init(unsigned long period)
  {
    myPeriod = period;
    timeElapsed = 0;
  }
  /**
   * Method that changes the state of the task, called by the Scheduler.
  */
  virtual void tick() = 0;

  /**
   * Checks the elapsed time of the Task based on the basePeriod declared.
   * @param baseperiod the base period of the task.
  */
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
  /**
   * Checks if the task is active or not.
   * @return true if the task is active, false otherwise.
  */
  virtual bool isActive();
 /**
   * Setter that sets the task as active or not.
   * @param active, indicates if the task is active or not.
  */
  virtual void setActive(bool active);

private:
  unsigned long myPeriod;
  unsigned long timeElapsed;
  bool active;
};

#endif
