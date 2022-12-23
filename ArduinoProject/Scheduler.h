#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Timer.h"
#include "Task.h"

#define MAX_TASKS 20

/**
 * Declaration of the class Scheduler.
*/
class Scheduler
{
    unsigned long basePeriod;
    int nTasks;
    Task *taskList[MAX_TASKS];
    Timer timer;

public:
    /**
     * Initialized the Scheduler.
     * @param basePeriod base period of the Scheduler to evaluate the different tasks.
    */
    void init(unsigned long basePeriod);
    /**
     * Add tasks to the lists of tsks of the Scheduler.
     * @param task the Task to add.
    */
    virtual bool addTask(Task *task);
    /**
     * Start the schedule.
    */
    virtual void schedule();
};
#endif
