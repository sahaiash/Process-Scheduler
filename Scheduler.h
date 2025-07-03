#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Process.h"
#include <vector>
#include <string>

class Scheduler {
protected:
    std::vector<Process> processes;
    std::string schedulerName;
    int currentTime;
    
public:
    // Constructor
    Scheduler(const std::string& name);
    
    // Virtual destructor (important for inheritance)
    virtual ~Scheduler() = default;
    
    // Core scheduling functions
    virtual void addProcess(const Process& process);
    virtual void schedule() = 0;  // Pure virtual function - must be implemented by derived classes
    virtual void displayResults() const;
    
    // Utility functions
    void reset();
    std::string getName() const { return schedulerName; }
    int getCurrentTime() const { return currentTime; }
    
    // Statistics calculation
    double calculateAverageWaitingTime() const;
    double calculateAverageTurnaroundTime() const;
    void evaluatePerformance() const;
    
protected:
    // Helper functions for derived classes
    void calculateTimings();
    void sortProcessesByArrivalTime();
    bool allProcessesCompleted() const;
};

#endif 
