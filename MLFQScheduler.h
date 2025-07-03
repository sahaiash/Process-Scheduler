#ifndef MLFQ_SCHEDULER_H
#define MLFQ_SCHEDULER_H

#include "Scheduler.h"
#include <vector>
#include <queue>

class MLFQScheduler : public Scheduler {
public:
    MLFQScheduler(const std::vector<int>& quanta);
    void schedule() override;
private:
    std::vector<int> quanta;
    void executeMLFQ();
};

#endif 