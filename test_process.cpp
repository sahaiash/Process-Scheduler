#include "Process.h"
#include <iostream>
using namespace std;
int main() {
    cout << "=== Process Scheduler Test ===\n\n";
    
    // Test Case 1: Creating a Process
    cout << "Test Case 1: Creating a Process\n";
    cout << "Creating Process(1, 'Chrome', 0, 10, 2)...\n";
    
    Process p1(1, "Chrome", 0, 10, 2);
    
    // Testing getters (defined in header, no implementation needed)
    cout << "Process ID: " << p1.getProcessId() << std::endl;
    cout << "Process Name: " << p1.getProcessName() << std::endl;
    cout << "Arrival Time: " << p1.getArrivalTime() << std::endl;
    cout << "Burst Time: " << p1.getBurstTime() << std::endl;
    cout << "Priority: " << p1.getPriority() << std::endl;
    cout << "Remaining Time: " << p1.getRemainingTime() << std::endl;
    cout << "Is Completed: " << (p1.isCompleted() ? "Yes" : "No") << std::endl;
    
    cout << "\n" << std::string(50, '-') << "\n\n";
    
    // Test Case 2: Simulating Process Execution
    cout << "Test Case 2: Simulating Process Execution\n";
    cout << "Initial remaining time: " << p1.getRemainingTime() << std::endl;
    
    // Simulate CPU execution (decrementing remaining time)
    for(int i = 1; i <= 3; i++) {
        p1.decrementRemainingTime();
        std::cout << "After " << i << " CPU cycle(s), remaining time: " 
                  << p1.getRemainingTime() << std::endl;
    }
    
    std::cout << "\n" << std::string(50, '-') << "\n\n";
    
    // Test Case 3: Setting Process Completion
    std::cout << "Test Case 3: Setting Process Completion\n";
    
    // Simulate process completion
    p1.setCompletionTime(15);
    p1.setWaitingTime(5);
    p1.setTurnaroundTime(15);
    
    cout << "Completion Time: " << p1.getCompletionTime() << std::endl;
    cout << "Waiting Time: " << p1.getWaitingTime() << std::endl;
    cout << "Turnaround Time: " << p1.getTurnaroundTime() << std::endl;
    
    cout << "\n" << std::string(50, '-') << "\n\n";
    
    // Test Case 4: Multiple Processes
    cout << "Test Case 4: Multiple Processes\n";
    
    Process p2(2, "Word", 2, 8, 1);
    Process p3(3, "Excel", 5, 12, 3);
    
    cout << "Process 2: " << p2.getProcessName() 
              << " (Priority: " << p2.getPriority() << ")\n";
    cout << "Process 3: " << p3.getProcessName() 
              << " (Priority: " << p3.getPriority() << ")\n";
    
    return 0;
} 