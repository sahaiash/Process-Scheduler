#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Process {
private:
    int processId;
    string processName;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;

public:
    // Constructor
    Process(int id, string name, int arrival, int burst, int prio = 0);
    
    // Getters
    int getProcessId() { return processId; }
    string getProcessName() { return processName; }
    int getArrivalTime() { return arrivalTime; }
    int getBurstTime() { return burstTime; }
    int getPriority() { return priority; }
    int getRemainingTime() { return remainingTime; }
    int getCompletionTime() { return completionTime; }
    int getWaitingTime() { return waitingTime; }
    int getTurnaroundTime() { return turnaroundTime; }
    
    // Setters
    void setRemainingTime(int time) { remainingTime = time; }
    void setCompletionTime(int time) { completionTime = time; }
    void setWaitingTime(int time) { waitingTime = time; }
    void setTurnaroundTime(int time) { turnaroundTime = time; }
    
    // Utility functions
    void decrementRemainingTime() { if (remainingTime > 0) remainingTime--; }
    bool isCompleted() const { return remainingTime == 0; }
};

#endif 