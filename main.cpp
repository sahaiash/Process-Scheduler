#include "FCFSScheduler.h"
#include "SJF_Scheduler.h"
#include "PriorityScheduler.h"
#include "RoundRobinScheduler.h"
#include "MLFQScheduler.h"
#include <iostream>
#include <iomanip>

int main() {
    // Define the test processes - Mixed workload to show MLFQ advantages
    std::vector<Process> testProcesses = {
        Process(1, "A", 0, 8, 1),    // Medium process
        Process(2, "B", 1, 4, 2),    // Short process
        Process(3, "C", 2, 9, 3),    // Long process
        Process(4, "D", 3, 5, 4),    // Medium process
        Process(5, "E", 4, 2, 2),    // Very short (interactive)
        Process(6, "F", 5, 6, 1),    // Medium process
        Process(7, "G", 6, 3, 3),    // Short process
        Process(8, "H", 7, 7, 4),    // Medium-long process
        Process(9, "I", 8, 1, 5),    // Very short (interactive)
        Process(10, "J", 9, 4, 2)    // Short process
    };

    // FCFS Scheduler
    FCFSScheduler fcfsScheduler;
    for (const auto& p : testProcesses) fcfsScheduler.addProcess(p);
    fcfsScheduler.schedule();
    fcfsScheduler.displayResults();

    // SJF Scheduler (Non-preemptive)
    SJFScheduler sjfScheduler(false);
    for (const auto& p : testProcesses) sjfScheduler.addProcess(p);
    sjfScheduler.schedule();
    sjfScheduler.displayResults();

    // SJF Scheduler (Preemptive/SRTF)
    SJFScheduler srtfScheduler(true);
    for (const auto& p : testProcesses) srtfScheduler.addProcess(p);
    srtfScheduler.schedule();
    srtfScheduler.displayResults();

    // Priority Scheduler (Non-preemptive)
    PriorityScheduler priorityScheduler;
    for (const auto& p : testProcesses) priorityScheduler.addProcess(p);
    priorityScheduler.schedule();
    priorityScheduler.displayResults();

    // Round Robin Scheduler (Quantum = 10)
    RoundRobinScheduler rrScheduler(10);
    for (const auto& p : testProcesses) rrScheduler.addProcess(p);
    rrScheduler.schedule();
    rrScheduler.displayResults();

    // Test Round Robin with different time quanta
    std::cout << "\n=== ROUND ROBIN TIME QUANTUM ANALYSIS ===\n";
    std::cout << "Time Quantum\tAvg Waiting Time\tAvg Turnaround Time\n";
    std::cout << std::string(50, '-') << "\n";
    
    for (int tq = 1; tq <= 20; tq++) {
        RoundRobinScheduler rr(tq);
        for (const auto& p : testProcesses) rr.addProcess(p);
        rr.schedule();
        std::cout << std::setw(12) << tq << "\t";
        rr.evaluatePerformance();
    }

    // MLFQ Scheduler (3 levels: quantum 2, 4, 8)
    std::vector<int> mlfqQuanta = {2, 4, 8};
    MLFQScheduler mlfqScheduler(mlfqQuanta);
    for (const auto& p : testProcesses) mlfqScheduler.addProcess(p);
    mlfqScheduler.schedule();
    mlfqScheduler.displayResults();

    // MLFQ Scheduler (Improved: quantum 4, 8, 16)
    std::vector<int> mlfqQuantaImproved = {4, 8, 16};
    MLFQScheduler mlfqSchedulerImproved(mlfqQuantaImproved);
    for (const auto& p : testProcesses) mlfqSchedulerImproved.addProcess(p);
    mlfqSchedulerImproved.schedule();
    mlfqSchedulerImproved.displayResults();

    // MLFQ Scheduler (Optimized: quantum 8, 16, 32)
    std::vector<int> mlfqQuantaOptimized = {8, 16, 32};
    MLFQScheduler mlfqSchedulerOptimized(mlfqQuantaOptimized);
    for (const auto& p : testProcesses) mlfqSchedulerOptimized.addProcess(p);
    mlfqSchedulerOptimized.schedule();
    mlfqSchedulerOptimized.displayResults();

    // Summary: Sort algorithms by performance
    std::cout << "\n=== ALGORITHM PERFORMANCE SUMMARY ===\n";
    std::cout << std::left << std::setw(25) << "Algorithm" << std::setw(18) << "Avg Waiting Time" << std::setw(18) << "Avg Turnaround Time" << "\n";
    std::cout << std::string(65, '-') << "\n";
    std::cout << std::left << std::setw(25) << "FCFS" << std::setw(18) << std::fixed << std::setprecision(2) << fcfsScheduler.calculateAverageWaitingTime() << std::setw(18) << fcfsScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "SJF (Non-preemptive)" << std::setw(18) << sjfScheduler.calculateAverageWaitingTime() << std::setw(18) << sjfScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "SJF (Preemptive/SRTF)" << std::setw(18) << srtfScheduler.calculateAverageWaitingTime() << std::setw(18) << srtfScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "Priority (Non-preemptive)" << std::setw(18) << priorityScheduler.calculateAverageWaitingTime() << std::setw(18) << priorityScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "Round Robin (Quantum=10)" << std::setw(18) << rrScheduler.calculateAverageWaitingTime() << std::setw(18) << rrScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "MLFQ (2,4,8)" << std::setw(18) << mlfqScheduler.calculateAverageWaitingTime() << std::setw(18) << mlfqScheduler.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "MLFQ (4,8,16)" << std::setw(18) << mlfqSchedulerImproved.calculateAverageWaitingTime() << std::setw(18) << mlfqSchedulerImproved.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::left << std::setw(25) << "MLFQ (8,16,32)" << std::setw(18) << mlfqSchedulerOptimized.calculateAverageWaitingTime() << std::setw(18) << mlfqSchedulerOptimized.calculateAverageTurnaroundTime() << "\n";
    std::cout << std::string(65, '-') << "\n";

    return 0;
}