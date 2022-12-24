#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Timer.h"
#include "Task.h"

#define MAX_TASKS 20

class Scheduler
{
    unsigned long basePeriod;
    int nTasks;
    Task *taskList[MAX_TASKS];
    Timer timer;

public:
    void init(unsigned long basePeriod);
    virtual bool addTask(Task *task);
    virtual void schedule();
};
#endif
