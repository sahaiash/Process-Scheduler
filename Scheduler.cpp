#include "Scheduler.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

Scheduler::Scheduler(const std::string& name) : schedulerName(name), currentTime(0) {}

void Scheduler::addProcess(const Process& process) {
    processes.push_back(process);
}

void Scheduler::reset() {
    processes.clear();
    currentTime = 0;
}

void Scheduler::sortProcessesByArrivalTime() {
    std::sort(processes.begin(), processes.end(), 
              [](const Process& a, const Process& b) {
                  return a.getArrivalTime() < b.getArrivalTime();
              });
}

bool Scheduler::allProcessesCompleted() const {
    for (const auto& process : processes) {
        if (!process.isCompleted()) {
            return false;
        }
    }
    return true;
}

void Scheduler::calculateTimings() {
    for (auto& process : processes) {
        // Calculate turnaround time
        int turnaroundTime = process.getCompletionTime() - process.getArrivalTime();
        process.setTurnaroundTime(turnaroundTime);
        
        // Calculate waiting time
        int waitingTime = turnaroundTime - process.getBurstTime();
        process.setWaitingTime(waitingTime);
    }
}

double Scheduler::calculateAverageWaitingTime() const {
    if (processes.empty()) return 0.0;
    
    double totalWaitingTime = 0.0;
    for (const auto& process : processes) {
        totalWaitingTime += process.getWaitingTime();
    }
    return totalWaitingTime / processes.size();
}

double Scheduler::calculateAverageTurnaroundTime() const {
    if (processes.empty()) return 0.0;
    
    double totalTurnaroundTime = 0.0;
    for (const auto& process : processes) {
        totalTurnaroundTime += process.getTurnaroundTime();
    }
    return totalTurnaroundTime / processes.size();
}

void Scheduler::displayResults() const {
    std::cout << "\n=== " << schedulerName << " Scheduling Results ===\n";
    std::cout << std::setw(5) << "PID" << std::setw(10) << "Name" 
              << std::setw(8) << "Arrival" << std::setw(8) << "Burst"
              << std::setw(8) << "Priority" << std::setw(12) << "Completion"
              << std::setw(10) << "Waiting" << std::setw(12) << "Turnaround" << "\n";
    std::cout << std::string(80, '-') << "\n";
    
    for (const auto& process : processes) {
        std::cout << std::setw(5) << process.getProcessId()
                  << std::setw(10) << process.getProcessName()
                  << std::setw(8) << process.getArrivalTime()
                  << std::setw(8) << process.getBurstTime()
                  << std::setw(8) << process.getPriority()
                  << std::setw(12) << process.getCompletionTime()
                  << std::setw(10) << process.getWaitingTime()
                  << std::setw(12) << process.getTurnaroundTime() << "\n";
    }
    
    std::cout << std::string(80, '-') << "\n";
    std::cout << "Average Waiting Time: " << std::fixed << std::setprecision(2) 
              << calculateAverageWaitingTime() << "\n";
    std::cout << "Average Turnaround Time: " << std::fixed << std::setprecision(2) 
              << calculateAverageTurnaroundTime() << "\n";
} 