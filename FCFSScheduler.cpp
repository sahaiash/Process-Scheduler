#include "FCFSScheduler.h"
#include <iostream>

FCFSScheduler::FCFSScheduler() : Scheduler("First Come First Serve (FCFS)") {}

void FCFSScheduler::schedule() {
    std::cout << "\n=== Executing FCFS Scheduling ===\n";
    sortProcessesByArrivalTime();
    executeFCFS();
    calculateTimings();
}

void FCFSScheduler::executeFCFS() {
    currentTime = 0;
    for (auto& process : processes) {
        if (currentTime < process.getArrivalTime()) {
            currentTime = process.getArrivalTime();
        }
        currentTime += process.getBurstTime();
        process.setCompletionTime(currentTime);
        process.setRemainingTime(0);
    }
}
