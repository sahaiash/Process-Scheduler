#include "RoundRobinScheduler.h"
#include <iostream>
#include <queue>

RoundRobinScheduler::RoundRobinScheduler(int quantum) : Scheduler("Round Robin Scheduling"), quantum(quantum) {}

void RoundRobinScheduler::schedule() {
    std::cout << "\n=== Executing Round Robin Scheduling (Quantum = " << quantum << ") ===\n";
    executeRoundRobin();
    calculateTimings();
}

void RoundRobinScheduler::executeRoundRobin() {
    int n = processes.size();
    std::vector<int> remaining(n);
    for (int i = 0; i < n; ++i) remaining[i] = processes[i].getBurstTime();
    std::vector<bool> completed(n, false);
    int completedCount = 0;
    currentTime = 0;
    std::queue<int> q;
    std::vector<bool> inQueue(n, false);
    int arrived = 0;
    // Enqueue processes that have arrived at time 0
    for (int i = 0; i < n; ++i) {
        if (processes[i].getArrivalTime() <= currentTime) {
            q.push(i);
            inQueue[i] = true;
            arrived++;
        }
    }
    while (completedCount < n) {
        if (q.empty()) {
            // If no process is ready, advance time to next arrival
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && !inQueue[i] && processes[i].getArrivalTime() > currentTime) {
                    nextArrival = std::min(nextArrival, processes[i].getArrivalTime());
                }
            }
            if (nextArrival == INT_MAX) break;
            currentTime = nextArrival;
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && !inQueue[i] && processes[i].getArrivalTime() <= currentTime) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }
        int idx = q.front(); q.pop();
        int execTime = std::min(quantum, remaining[idx]);
        int startTime = currentTime;
        currentTime += execTime;
        remaining[idx] -= execTime;
        // Enqueue any new arrivals during this time slice
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && !inQueue[i] && processes[i].getArrivalTime() > startTime && processes[i].getArrivalTime() <= currentTime) {
                q.push(i);
                inQueue[i] = true;
            }
        }
        if (remaining[idx] == 0) {
            completed[idx] = true;
            completedCount++;
            processes[idx].setCompletionTime(currentTime);
            processes[idx].setRemainingTime(0);
        } else {
            processes[idx].setRemainingTime(remaining[idx]);
            q.push(idx);
        }
    }
} 