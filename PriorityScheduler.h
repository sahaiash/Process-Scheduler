#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include "Scheduler.h"

class PriorityScheduler : public Scheduler {
public:
    PriorityScheduler();
    void schedule() override;
private:
    void executePriority();
};

#endif 