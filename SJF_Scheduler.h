#ifndef SJF_SCHEDULER_H
#define SJF_SCHEDULER_H

#include "Scheduler.h"

class SJFScheduler : public Scheduler {
public:
    SJFScheduler(bool preemptive = false);
    void schedule() override;
private:
    bool preemptive;
    void executeSJF();
    void executeSRTF(); // Preemptive SJF (Shortest Remaining Time First)
};

#endif 