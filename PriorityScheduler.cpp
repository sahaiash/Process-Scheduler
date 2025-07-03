#include "PriorityScheduler.h"
#include <iostream>
#include <algorithm>

PriorityScheduler::PriorityScheduler() : Scheduler("Priority Scheduling") {}

void PriorityScheduler::schedule() {
    std::cout << "\n=== Executing Priority Scheduling ===\n";
    executePriority();
    calculateTimings();
}

void PriorityScheduler::executePriority() {
    currentTime = 0;
    int n = processes.size();
    std::vector<bool> completed(n, false);
    int completedCount = 0;
    while (completedCount < n) {
        int idx = -1;
        int highestPriority = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].getArrivalTime() <= currentTime) {
                if (processes[i].getPriority() < highestPriority) {
                    highestPriority = processes[i].getPriority();
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            currentTime++;
            continue;
        }
        currentTime += processes[idx].getBurstTime();
        processes[idx].setCompletionTime(currentTime);
        processes[idx].setRemainingTime(0);
        completed[idx] = true;
        completedCount++;
    }
} 