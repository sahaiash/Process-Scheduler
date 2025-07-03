#include "SJF_Scheduler.h"
#include <iostream>
#include <algorithm>

SJFScheduler::SJFScheduler(bool preemptive) : Scheduler(preemptive ? "Shortest Job First (SJF, Preemptive)" : "Shortest Job First (SJF)"), preemptive(preemptive) {}

void SJFScheduler::schedule() {
    if (preemptive) {
        std::cout << "\n=== Executing SJF (Preemptive/SRTF) Scheduling ===\n";
        executeSRTF();
    } else {
        std::cout << "\n=== Executing SJF Scheduling ===\n";
        executeSJF();
    }
    calculateTimings();
}

void SJFScheduler::executeSJF() {
    currentTime = 0;
    std::vector<bool> completed(processes.size(), false);
    int completedCount = 0;
    int n = processes.size();
    while (completedCount < n) {
        int idx = -1;
        int minBurst = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].getArrivalTime() <= currentTime) {
                if (processes[i].getBurstTime() < minBurst) {
                    minBurst = processes[i].getBurstTime();
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

void SJFScheduler::executeSRTF() {
    int n = processes.size();
    currentTime = 0;
    int completedCount = 0;
    std::vector<int> remaining(n);
    for (int i = 0; i < n; ++i) remaining[i] = processes[i].getBurstTime();
    std::vector<bool> completed(n, false);
    int lastProcess = -1;
    while (completedCount < n) {
        int idx = -1;
        int minRem = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].getArrivalTime() <= currentTime && remaining[i] > 0) {
                if (remaining[i] < minRem) {
                    minRem = remaining[i];
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            currentTime++;
            continue;
        }
        remaining[idx]--;
        if (remaining[idx] == 0) {
            completed[idx] = true;
            completedCount++;
            processes[idx].setCompletionTime(currentTime + 1);
            processes[idx].setRemainingTime(0);
        } else {
            processes[idx].setRemainingTime(remaining[idx]);
        }
        currentTime++;
    }
} 