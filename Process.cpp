#include "Process.h"

Process::Process(int id, std::string name, int arrival, int burst, int prio) {
    processId = id;
    processName = name;
    arrivalTime = arrival;
    burstTime = burst;
    priority = prio;
    remainingTime = burst;  // Initially, remaining time equals burst time
    completionTime = 0;
    waitingTime = 0;
    turnaroundTime = 0;
} 