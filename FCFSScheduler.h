#ifndef FCFS_SCHEDULER_H
#define FCFS_SCHEDULER_H

#include "Scheduler.h"

class FCFSScheduler : public Scheduler {
public:
    // Constructor
    FCFSScheduler();
    
    // Override the pure virtual function
    void schedule() override;
    
private:
    // FCFS specific helper functions
    void executeFCFS();
};

#endif 