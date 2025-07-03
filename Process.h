#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
private:
    int processId;
    std::string processName;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;

public:
    // Constructor
    Process(int id, const std::string& name, int arrival, int burst, int prio = 0);

    // Getters
    int getProcessId() const { return processId; }
    std::string getProcessName() const { return processName; }
    int getArrivalTime() const { return arrivalTime; }
    int getBurstTime() const { return burstTime; }
    int getPriority() const { return priority; }
    int getRemainingTime() const { return remainingTime; }
    int getCompletionTime() const { return completionTime; }
    int getWaitingTime() const { return waitingTime; }
    int getTurnaroundTime() const { return turnaroundTime; }

    // Setters
    void setRemainingTime(int time) { remainingTime = time; }
    void setCompletionTime(int time) { completionTime = time; }
    void setWaitingTime(int time) { waitingTime = time; }
    void setTurnaroundTime(int time) { turnaroundTime = time; }

    // Utility functions
    void decrementRemainingTime() { if (remainingTime > 0) remainingTime--; }
    bool isCompleted() const { return remainingTime == 0; }
};

#endif // PROCESS_H