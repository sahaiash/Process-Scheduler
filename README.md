# Process Scheduler

This project implements several classic CPU scheduling algorithms in C++:

- **First Come First Serve (FCFS)**
- **Shortest Job First (SJF, Non-preemptive)**
- **Shortest Job First (SJF, Preemptive/SRTF)**
- **Priority Scheduling (Non-preemptive)**

## Features
- Add processes with custom arrival time, burst time, and priority.
- Compare the results (waiting time, turnaround time, etc.) of different scheduling algorithms on the same set of processes.
- Console output with detailed statistics for each algorithm.

## How to Build and Run

1. **Clone the repository:**
   ```sh
   git clone https://github.com/sahaiash/Process-Scheduler.git
   cd Process-Scheduler
   ```
2. **Build the project:**
   ```sh
   g++ -std=c++17 -o process_scheduler main.cpp FCFSScheduler.cpp SJF_Scheduler.cpp PriorityScheduler.cpp Scheduler.cpp Process.cpp
   ```
3. **Run the executable:**
   ```sh
   ./process_scheduler
   ```

## Example Output
```
=== Executing FCFS Scheduling ===
... (table of results)
=== Executing SJF Scheduling ===
... (table of results)
=== Executing SJF (Preemptive/SRTF) Scheduling ===
... (table of results)
=== Executing Priority Scheduling ===
... (table of results)
```

## Customizing Processes
- Edit `main.cpp` to add or modify the processes and see how the algorithms perform on different inputs.

## File Structure
- `main.cpp` - Entry point, sets up and runs all schedulers
- `FCFSScheduler.*` - FCFS algorithm
- `SJF_Scheduler.*` - SJF (preemptive and non-preemptive)
- `PriorityScheduler.*` - Priority scheduling
- `Scheduler.*` - Base scheduler class
- `Process.*` - Process class

## License
MIT 