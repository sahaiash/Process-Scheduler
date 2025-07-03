#include "FCFSScheduler.h"
#include "SJF_Scheduler.h"
#include <iostream>

int main() {
    // Define the test processes
    std::vector<Process> testProcesses = {
        Process(1, "A", 0, 8, 1),
        Process(2, "B", 1, 4, 2),
        Process(3, "C", 2, 9, 3),
        Process(4, "D", 3, 5, 4)
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

    return 0;
}