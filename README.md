# Process Scheduler

A comprehensive CPU scheduling algorithm simulator implemented in C++ that demonstrates and compares various scheduling algorithms with detailed performance analysis.

## Implemented Algorithms

### Non-Preemptive Algorithms
- **First Come First Serve (FCFS)** - Processes are executed in order of arrival
- **Shortest Job First (SJF)** - Processes with shortest burst time are executed first
- **Priority Scheduling** - Processes are executed based on priority (lower number = higher priority)

### Preemptive Algorithms
- **Shortest Job First (Preemptive/SRTF)** - Shortest Remaining Time First
- **Round Robin (RR)** - Processes get CPU time in fixed time slices
- **Multi-Level Feedback Queue (MLFQ)** - Multiple priority queues with aging mechanism

## Features

- **Comprehensive Algorithm Comparison**: Compare all algorithms on the same process set
- **Time Quantum Analysis**: Test Round Robin with different time quanta (1-20)
- **Performance Metrics**: Average Waiting Time, Average Turnaround Time
- **Mixed Workload Support**: Handles interactive and CPU-bound processes
- **Configurable Parameters**: Adjustable time quanta for RR and MLFQ
- **Detailed Output**: Process-by-process breakdown and summary tables

## How to Build and Run

1. **Clone the repository:**
   ```sh
   git clone https://github.com/sahaiash/Process-Scheduler.git
   cd Process-Scheduler
   ```

2. **Build the project:**
   ```sh
   g++ -std=c++17 -o process_scheduler main.cpp FCFSScheduler.cpp SJF_Scheduler.cpp PriorityScheduler.cpp RoundRobinScheduler.cpp MLFQScheduler.cpp Scheduler.cpp Process.cpp
   ```

3. **Run the executable:**
   ```sh
   ./process_scheduler
   ```

## Example Output

The program provides:
- Detailed results for each algorithm
- Round Robin time quantum analysis (1-20)
- Performance comparison summary table
- Process-by-process statistics

```
=== ALGORITHM PERFORMANCE SUMMARY ===
Algorithm                Avg Waiting Time  Avg Turnaround Time
-----------------------------------------------------------------
FCFS                     21.00             25.90             
SJF (Non-preemptive)     13.70             18.60             
SJF (Preemptive/SRTF)    12.10             17.00             
Priority (Non-preemptive)19.70             24.60             
Round Robin (Quantum=10) 21.00             25.90             
MLFQ (2,4,8)             24.80             29.70             
MLFQ (4,8,16)            24.10             29.00             
MLFQ (8,16,32)           23.10             28.00             
-----------------------------------------------------------------
```

## Customizing Processes

Edit `main.cpp` to modify the test processes:
```cpp
std::vector<Process> testProcesses = {
    Process(1, "A", 0, 8, 1),    // (id, name, arrival, burst, priority)
    Process(2, "B", 1, 4, 2),    // Short process
    Process(3, "C", 2, 9, 3),    // Long process
    // ... add more processes
};
```

## File Structure

- `main.cpp` - Entry point with algorithm testing and analysis
- `FCFSScheduler.*` - First Come First Serve implementation
- `SJF_Scheduler.*` - Shortest Job First (preemptive and non-preemptive)
- `PriorityScheduler.*` - Priority-based scheduling
- `RoundRobinScheduler.*` - Round Robin with configurable quantum
- `MLFQScheduler.*` - Multi-Level Feedback Queue with aging
- `Scheduler.*` - Base scheduler class with common functionality
- `Process.*` - Process class with all necessary attributes

## Key Insights

- **SJF Preemptive (SRTF)** typically performs best for most workloads
- **Round Robin** performance heavily depends on time quantum selection
- **MLFQ** works best with larger quanta and mixed workloads
- **Time quantum = 8** was optimal for the test workload
- **Aging mechanism** in MLFQ prevents starvation

## License

MIT 