#include "FCFSScheduler.h"
#include <iostream>

int main() {
    FCFSScheduler scheduler;

    // Add some test processes: (id, name, arrival, burst, priority)
    scheduler.addProcess(Process(1, "A", 0, 20, 1));
    scheduler.addProcess(Process(2, "B", 1, 2, 2));
    scheduler.addProcess(Process(3, "C", 2, 2, 3));
 
    // Run the FCFS scheduling algorithm
    scheduler.schedule();

    // Display the results
    scheduler.displayResults();

    return 0;
}