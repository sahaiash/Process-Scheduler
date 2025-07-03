# Process Scheduler - Comprehensive CPU Scheduling Algorithm Simulator

A sophisticated CPU scheduling algorithm simulator implemented in C++ that provides detailed analysis and comparison of various scheduling algorithms. This project is designed for educational purposes, research, and understanding the performance characteristics of different CPU scheduling strategies.

## Table of Contents
- [Overview](#overview)
- [Implemented Algorithms](#implemented-algorithms)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Details](#algorithm-details)
- [Performance Analysis](#performance-analysis)
- [Customization](#customization)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Overview

This project implements and compares six major CPU scheduling algorithms, providing detailed performance metrics and analysis. It's particularly useful for:
- **Computer Science Education**: Understanding scheduling concepts
- **Performance Research**: Comparing algorithm efficiency
- **System Design**: Choosing appropriate scheduling strategies
- **Algorithm Analysis**: Studying time complexity and performance characteristics

## Implemented Algorithms

### Non-Preemptive Algorithms

#### 1. First Come First Serve (FCFS)
- **Principle**: Processes are executed in the order they arrive
- **Advantages**: Simple, fair, no starvation
- **Disadvantages**: Poor performance with varying burst times
- **Best For**: Batch processing, simple systems
- **Time Complexity**: O(n log n) for sorting

#### 2. Shortest Job First (SJF)
- **Principle**: Process with shortest burst time executes first
- **Advantages**: Optimal average waiting time
- **Disadvantages**: Requires knowledge of burst times, potential starvation
- **Best For**: Batch systems with known process characteristics
- **Time Complexity**: O(n log n) for sorting

#### 3. Priority Scheduling
- **Principle**: Processes executed based on priority (lower number = higher priority)
- **Advantages**: Supports process priorities
- **Disadvantages**: Potential starvation, priority inversion
- **Best For**: Real-time systems, priority-based applications
- **Time Complexity**: O(n log n) for sorting

### Preemptive Algorithms

#### 4. Shortest Job First (Preemptive/SRTF)
- **Principle**: Shortest Remaining Time First - preempts running process if shorter job arrives
- **Advantages**: Optimal average waiting time, responsive
- **Disadvantages**: Complex implementation, overhead
- **Best For**: Interactive systems, time-sharing
- **Time Complexity**: O(n²) in worst case

#### 5. Round Robin (RR)
- **Principle**: Each process gets CPU time in fixed time slices (quantum)
- **Advantages**: Fair, no starvation, good for time-sharing
- **Disadvantages**: Performance depends heavily on quantum size
- **Best For**: Time-sharing systems, interactive applications
- **Time Complexity**: O(n) per time slice

#### 6. Multi-Level Feedback Queue (MLFQ)
- **Principle**: Multiple priority queues with aging mechanism
- **Advantages**: Adapts to process behavior, prevents starvation
- **Disadvantages**: Complex, requires tuning
- **Best For**: Interactive systems with mixed workloads
- **Time Complexity**: O(n) per queue level

## Features

### Core Features
- **Comprehensive Algorithm Implementation**: All major scheduling algorithms
- **Performance Metrics**: Average Waiting Time, Average Turnaround Time
- **Process-by-Process Analysis**: Detailed statistics for each process
- **Mixed Workload Support**: Handles interactive and CPU-bound processes

### Advanced Features
- **Time Quantum Analysis**: Automatic testing of Round Robin with quanta 1-20
- **Configurable Parameters**: Adjustable time quanta for RR and MLFQ
- **Multiple MLFQ Configurations**: Test different queue setups
- **Performance Comparison Tables**: Side-by-side algorithm comparison
- **Detailed Output Formatting**: Professional console output

### Analysis Capabilities
- **Real-time Performance Monitoring**: Track algorithm execution
- **Statistical Analysis**: Calculate averages and trends
- **Comparative Studies**: Compare algorithms on same workload
- **Parameter Optimization**: Find optimal quantum values

## Installation

### Prerequisites
- **C++ Compiler**: GCC 7.0+ or Clang 5.0+
- **Make** (optional, for build automation)
- **Git** (for cloning)

### Step-by-Step Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/sahaiash/Process-Scheduler.git
   cd Process-Scheduler
   ```

2. **Verify files are present:**
   ```bash
   ls -la
   # Should show: main.cpp, *Scheduler.*, Process.*, README.md
   ```

3. **Build the project:**
   ```bash
   g++ -std=c++17 -o process_scheduler main.cpp FCFSScheduler.cpp SJF_Scheduler.cpp PriorityScheduler.cpp RoundRobinScheduler.cpp MLFQScheduler.cpp Scheduler.cpp Process.cpp
   ```

4. **Run the program:**
   ```bash
   ./process_scheduler
   ```

### Alternative Build Methods

**Using Make (if Makefile is available):**
```bash
make
./process_scheduler
```

**Debug Build:**
```bash
g++ -std=c++17 -g -o process_scheduler_debug main.cpp *.cpp
```

## Usage

### Basic Usage
```bash
./process_scheduler
```

### Expected Output
The program will display:
1. Detailed results for each algorithm
2. Round Robin time quantum analysis
3. Performance comparison summary
4. Process-by-process statistics

### Understanding the Output

#### Process Table Format
```
  PID      Name Arrival   BurstPriority  Completion   Waiting  Turnaround
--------------------------------------------------------------------------------
    1         A       0       8       1           8         0           8
    2         B       1       4       2          12         7          11
```

**Columns Explained:**
- **PID**: Process ID
- **Name**: Process name
- **Arrival**: Arrival time
- **Burst**: Burst time (execution time)
- **Priority**: Process priority (lower = higher priority)
- **Completion**: Time when process completes
- **Waiting**: Total waiting time
- **Turnaround**: Total turnaround time

#### Performance Summary
```
=== ALGORITHM PERFORMANCE SUMMARY ===
Algorithm                Avg Waiting Time  Avg Turnaround Time
-----------------------------------------------------------------
FCFS                     21.00             25.90             
SJF (Preemptive/SRTF)    12.10             17.00             
```

## Algorithm Details

### How Each Algorithm Works

#### FCFS (First Come First Serve)
```cpp
// Processes are sorted by arrival time
// Each process runs to completion before next starts
for (auto& process : processes) {
    if (currentTime < process.getArrivalTime()) {
        currentTime = process.getArrivalTime();
    }
    currentTime += process.getBurstTime();
    process.setCompletionTime(currentTime);
}
```

#### SJF (Shortest Job First)
```cpp
// Find shortest job among arrived processes
int minBurst = INT_MAX;
for (int i = 0; i < n; ++i) {
    if (!completed[i] && processes[i].getArrivalTime() <= currentTime) {
        if (processes[i].getBurstTime() < minBurst) {
            minBurst = processes[i].getBurstTime();
            idx = i;
        }
    }
}
```

#### Round Robin
```cpp
// Each process gets quantum time
int execTime = std::min(quantum, remaining[processIdx]);
currentTime += execTime;
remaining[processIdx] -= execTime;

// If not completed, add to end of queue
if (remaining[processIdx] > 0) {
    queue.push(processIdx);
}
```

### Performance Characteristics

| Algorithm | Avg Waiting Time | Avg Turnaround | Fairness | Starvation | Complexity |
|-----------|------------------|----------------|----------|------------|------------|
| FCFS | High | High | Good | No | O(n log n) |
| SJF | Low | Low | Poor | Yes | O(n log n) |
| Priority | Medium | Medium | Poor | Yes | O(n log n) |
| SRTF | Lowest | Lowest | Poor | Yes | O(n²) |
| RR | Medium | Medium | Best | No | O(n) |
| MLFQ | Medium | Medium | Good | No | O(n) |

## Performance Analysis

### Time Quantum Analysis for Round Robin

The program automatically tests Round Robin with time quanta from 1 to 20:

```
=== ROUND ROBIN TIME QUANTUM ANALYSIS ===
Time Quantum    Avg Waiting Time        Avg Turnaround Time
--------------------------------------------------
           1    Avg WT: 24.90, Avg TAT: 29.80
           2    Avg WT: 24.60, Avg TAT: 29.50
           8    Avg WT: 23.10, Avg TAT: 28.00  # Optimal
          10    Avg WT: 21.00, Avg TAT: 25.90
```

### Key Performance Insights

1. **Optimal Quantum Selection**: Quantum = 8 performs best for the test workload
2. **Quantum vs Performance**: Larger quanta reduce context switching overhead
3. **Algorithm Ranking**: SRTF > SJF > Priority > RR > FCFS > MLFQ (for this workload)
4. **MLFQ Tuning**: Larger quanta (8,16,32) perform better than small quanta (2,4,8)

### Performance Optimization Tips

- **For Interactive Systems**: Use RR with quantum 2-8
- **For Batch Processing**: Use SJF or SRTF
- **For Mixed Workloads**: Use MLFQ with aging
- **For Real-time Systems**: Use Priority scheduling

## Customization

### Modifying Test Processes

Edit `main.cpp` to change the test workload:

```cpp
std::vector<Process> testProcesses = {
    Process(1, "A", 0, 8, 1),    // (id, name, arrival, burst, priority)
    Process(2, "B", 1, 4, 2),    // Short process
    Process(3, "C", 2, 9, 3),    // Long process
    Process(4, "D", 3, 5, 4),    // Medium process
    Process(5, "E", 4, 2, 2),    // Very short (interactive)
    // Add more processes as needed
};
```

### Adding New Algorithms

1. Create header file: `NewScheduler.h`
2. Create implementation: `NewScheduler.cpp`
3. Inherit from base class: `class NewScheduler : public Scheduler`
4. Implement virtual methods: `schedule()` and helper functions
5. Add to main.cpp and build command

### Example: Adding Custom Scheduler

```cpp
// NewScheduler.h
class NewScheduler : public Scheduler {
public:
    NewScheduler();
    void schedule() override;
private:
    void executeNewAlgorithm();
};

// main.cpp
NewScheduler newScheduler;
for (const auto& p : testProcesses) newScheduler.addProcess(p);
newScheduler.schedule();
newScheduler.displayResults();
```

### Configuring MLFQ Parameters

```cpp
// Different queue configurations
std::vector<int> mlfqQuanta1 = {2, 4, 8};      // Small quanta
std::vector<int> mlfqQuanta2 = {4, 8, 16};     // Medium quanta
std::vector<int> mlfqQuanta3 = {8, 16, 32};    // Large quanta
```

## File Structure

```
process_scheduler/
├── main.cpp                 # Main program with algorithm testing
├── Process.h               # Process class definition
├── Process.cpp             # Process class implementation
├── Scheduler.h             # Base scheduler class
├── Scheduler.cpp           # Base scheduler implementation
├── FCFSScheduler.h         # FCFS algorithm header
├── FCFSScheduler.cpp       # FCFS algorithm implementation
├── SJF_Scheduler.h         # SJF algorithm header
├── SJF_Scheduler.cpp       # SJF algorithm implementation
├── PriorityScheduler.h     # Priority algorithm header
├── PriorityScheduler.cpp   # Priority algorithm implementation
├── RoundRobinScheduler.h   # Round Robin algorithm header
├── RoundRobinScheduler.cpp # Round Robin algorithm implementation
├── MLFQScheduler.h         # MLFQ algorithm header
├── MLFQScheduler.cpp       # MLFQ algorithm implementation
├── README.md               # This documentation
└── process_scheduler       # Compiled executable
```

### Class Hierarchy

```
Scheduler (Base Class)
├── FCFSScheduler
├── SJFScheduler
├── PriorityScheduler
├── RoundRobinScheduler
└── MLFQScheduler
```

## Contributing

### How to Contribute

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/new-algorithm`
3. **Make your changes**
4. **Test thoroughly**: Ensure all algorithms work correctly
5. **Update documentation**: Modify README if needed
6. **Submit a pull request**

### Development Guidelines

- **Code Style**: Follow existing C++ conventions
- **Documentation**: Add comments for complex algorithms
- **Testing**: Test with different process sets
- **Performance**: Consider algorithm efficiency

### Adding New Features

- **New Algorithms**: Implement as separate classes
- **Performance Metrics**: Add to base Scheduler class
- **Analysis Tools**: Create utility functions
- **Visualization**: Add output formatting options

## Troubleshooting

### Common Issues

#### Compilation Errors

**Error: "out-of-line definition does not match declaration"**
```bash
# Solution: Check parameter types match between .h and .cpp files
# Example: const std::string& vs std::string
```

**Error: "undefined reference to..."**
```bash
# Solution: Ensure all .cpp files are included in compilation
g++ -std=c++17 -o process_scheduler *.cpp
```

#### Runtime Issues

**Program crashes or hangs**
- Check for infinite loops in scheduling algorithms
- Verify process arrival times are valid
- Ensure quantum values are positive

**Incorrect results**
- Verify process parameters (arrival, burst, priority)
- Check algorithm implementation logic
- Compare with expected theoretical results

### Debugging Tips

1. **Add debug output**:
   ```cpp
   std::cout << "Debug: Processing " << processIdx << " at time " << currentTime << std::endl;
   ```

2. **Use smaller test cases**:
   ```cpp
   std::vector<Process> testProcesses = {
       Process(1, "A", 0, 5, 1),
       Process(2, "B", 1, 3, 2)
   };
   ```

3. **Check intermediate values**:
   ```cpp
   std::cout << "Remaining time: " << remaining[processIdx] << std::endl;
   ```

### Performance Issues

**Slow execution with large process sets**
- Consider algorithm complexity
- Optimize data structures
- Use more efficient sorting

**Memory issues**
- Check for memory leaks
- Use smart pointers where appropriate
- Monitor memory usage

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### MIT License Summary
- **Use**: Free to use for any purpose
- **Modify**: Can modify and distribute
- **Commercial**: Can use commercially
- **Attribution**: Include original license and copyright notice

## Acknowledgments

- **Operating Systems Concepts**: Based on standard scheduling algorithms
- **C++ Community**: For best practices and conventions
- **Open Source**: Built with open source tools and libraries

## Contact

For questions, issues, or contributions:
- **GitHub Issues**: [Create an issue](https://github.com/sahaiash/Process-Scheduler/issues)
- **Pull Requests**: [Submit a PR](https://github.com/sahaiash/Process-Scheduler/pulls)
- **Documentation**: Check this README and code comments

---

**Note**: This project is designed for educational and research purposes. For production systems, consider using established scheduling libraries and frameworks. 