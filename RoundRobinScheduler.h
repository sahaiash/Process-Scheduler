#ifndef ROUND_ROBIN_SCHEDULER_H
#define ROUND_ROBIN_SCHEDULER_H

#include "Scheduler.h"

class RoundRobinScheduler : public Scheduler {
public:
    RoundRobinScheduler(int quantum);
    void schedule() override;
private:
    int quantum;
    void executeRoundRobin();
};

#endif 