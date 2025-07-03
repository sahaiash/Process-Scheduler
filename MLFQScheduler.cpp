#include "MLFQScheduler.h"
#include <iostream>
#include <algorithm>

MLFQScheduler::MLFQScheduler(const std::vector<int>& quanta) : Scheduler("Multi-Level Feedback Queue (MLFQ)"), quanta(quanta) {}

void MLFQScheduler::schedule() {
    std::cout << "\n=== Executing MLFQ Scheduling ===\n";
    std::cout << "Queue levels: " << quanta.size() << " with quanta: ";
    for (size_t i = 0; i < quanta.size(); ++i) {
        std::cout << quanta[i];
        if (i < quanta.size() - 1) std::cout << ", ";
    }
    std::cout << "\n";
    executeMLFQ();
    calculateTimings();
}

void MLFQScheduler::executeMLFQ() {
    int n = processes.size();
    std::vector<std::queue<int>> queues(quanta.size());
    std::vector<int> remaining(n);
    std::vector<int> queueLevel(n, 0);
    std::vector<bool> completed(n, false);
    std::vector<int> timeInQueue(n, 0);
    int completedCount = 0;
    currentTime = 0;
    
    // Initialize remaining times
    for (int i = 0; i < n; ++i) {
        remaining[i] = processes[i].getBurstTime();
    }
    
    // Add processes that have arrived at time 0 to the highest priority queue
    for (int i = 0; i < n; ++i) {
        if (processes[i].getArrivalTime() <= currentTime) {
            queues[0].push(i);
        }
    }
    
    while (completedCount < n) {
        // Find the highest priority non-empty queue
        int currentQueue = -1;
        for (int q = 0; q < quanta.size(); ++q) {
            if (!queues[q].empty()) {
                currentQueue = q;
                break;
            }
        }
        
        if (currentQueue == -1) {
            // No process is ready, advance time to next arrival
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && processes[i].getArrivalTime() > currentTime) {
                    nextArrival = std::min(nextArrival, processes[i].getArrivalTime());
                }
            }
            if (nextArrival == INT_MAX) break;
            currentTime = nextArrival;
            
            // Add newly arrived processes to highest priority queue
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && processes[i].getArrivalTime() <= currentTime) {
                    bool alreadyInQueue = false;
                    for (int q = 0; q < quanta.size(); ++q) {
                        std::queue<int> temp = queues[q];
                        while (!temp.empty()) {
                            if (temp.front() == i) {
                                alreadyInQueue = true;
                                break;
                            }
                            temp.pop();
                        }
                        if (alreadyInQueue) break;
                    }
                    if (!alreadyInQueue) {
                        queues[0].push(i);
                        queueLevel[i] = 0;
                        timeInQueue[i] = 0;
                    }
                }
            }
            continue;
        }
        
        int processIdx = queues[currentQueue].front();
        queues[currentQueue].pop();
        
        int execTime = std::min(quanta[currentQueue], remaining[processIdx]);
        int startTime = currentTime;
        currentTime += execTime;
        remaining[processIdx] -= execTime;
        
        // Add newly arrived processes during execution
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].getArrivalTime() > startTime && processes[i].getArrivalTime() <= currentTime) {
                bool alreadyInQueue = false;
                for (int q = 0; q < quanta.size(); ++q) {
                    std::queue<int> temp = queues[q];
                    while (!temp.empty()) {
                        if (temp.front() == i) {
                            alreadyInQueue = true;
                            break;
                        }
                        temp.pop();
                    }
                    if (alreadyInQueue) break;
                }
                if (!alreadyInQueue) {
                    queues[0].push(i);
                    queueLevel[i] = 0;
                    timeInQueue[i] = 0;
                }
            }
        }
        
        if (remaining[processIdx] == 0) {
            // Process completed
            completed[processIdx] = true;
            completedCount++;
            processes[processIdx].setCompletionTime(currentTime);
            processes[processIdx].setRemainingTime(0);
        } else {
            // Process not completed, move to lower priority queue
            int nextQueue = std::min(currentQueue + 1, (int)quanta.size() - 1);
            queues[nextQueue].push(processIdx);
            queueLevel[processIdx] = nextQueue;
        }
        
        // Simplified aging: only age up processes in lowest queue after longer wait
        if (currentQueue == quanta.size() - 1 && !queues[currentQueue].empty()) {
            std::queue<int> temp;
            while (!queues[currentQueue].empty()) {
                int p = queues[currentQueue].front();
                queues[currentQueue].pop();
                timeInQueue[p]++;
                
                // Age up if waiting too long (20 time units for lowest queue)
                if (timeInQueue[p] >= 20) {
                    queues[0].push(p);
                    queueLevel[p] = 0;
                    timeInQueue[p] = 0;
                } else {
                    temp.push(p);
                }
            }
            queues[currentQueue] = temp;
        }
    }
} 