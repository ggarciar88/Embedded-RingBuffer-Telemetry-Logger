```text
                     _           ___   ___  
                    (_)         / _ \ / _ \    not©         not©         not©         not©         not©         not©         not©         not©         not©
   __ _ __ _ __ _ __ ___ _ __ _ _  __| (_) | (_) |        not©         not©         not©         not©         not©         not©         not©         not©         not©    
  / _` |/ _` |/ _` | '__/ __| |/ _` |   > _ < > _ <             not©         not©         not©         not©         not©         not©         not©         not©         not©     
 | (_| | (_| | (_| | |  (__| | (_| | || (_) | (_) |
  \__, |\__, |\__,_|_|\_ ___|_|\__,_|_| \___/ \___/                  
   __/ | __/ |                                       
  |___/ |___/

@ggarciar88  // Embedded-RingBuffer-Telemetry-Logger
______________________________________________________________________________________________________________________________________________________________________________________________________________________
# Embedded Ring Buffer & Thread-Safe Telemetry Logger
______________________________________________________________________________________________________________________________________________________________________________________________________________________

A high-performance C++17 project implementing a lock-free/thread-safe ring buffer and a multithreaded telemetry logging framework. Designed for low-level systems and embedded-style execution where memory constraints and concurrency safety are critical.

## Features

- Thread-safe ring buffer implementation using standard concurrency primitives (`std::mutex`, `std::atomic`)
- Multithreaded telemetry logging capable of handling asynchronous producer-consumer events
- Optimized for resource-constrained and high-performance environments
- Clean, modular C++ architecture with zero external dependencies

## File Structure

- `RingBufferLogger.hpp`: Core template ring buffer and telemetry logger classes
- `main.cpp`: Multi-producer and consumer execution demonstration
- `CMakeLists.txt`: Build configuration file

## How It Works

- Multiple producer threads generate diagnostic events and push them into the concurrent ring buffer.
- A dedicated consumer thread fetches and processes telemetry data safely.
- Employs thread synchronization mechanisms to prevent data races and buffer overflows.

## How to Run

1. Ensure a C++17 compatible compiler and CMake are installed.
2. Build and run using the terminal:

        mkdir build && cd build
        cmake ..
        make
        ./telemetry_app

## Future Improvements

- Lock-free implementation using atomic pointers for ultra-low latency
- Persistent storage backend (binary file dumping)

## License

This project is open-source and free to use for educational and personal learning purposes.
Released under the MIT License (view LICENSE file).
2. HIL-Test-Automation-Framework
Plaintext
                     _           ___   ___  
                    (_)         / _ \ / _ \    not©         not©         not©         not©         not©         not©         not©         not©         not©
   __ _ __ _ __ _ __ ___ _ __ _ _  __| (_) | (_) |        not©         not©         not©         not©         not©         not©         not©         not©         not©    
  / _` |/ _` |/ _` | '__/ __| |/ _` |   > _ < > _ <             not©         not©         not©         not©         not©         not©         not©         not©         not©     
 | (_| | (_| | (_| | |  (__| | (_| | || (_) | (_) |
  \__, |\__, |\__,_|_|\_ ___|_|\__,_|_| \___/ \___/                  
   __/ | __/ |                                       
  |___/ |___/                                        
     

@ggarciar88  // HIL-Test-Automation-Framework
______________________________________________________________________________________________________________________________________________________________________________________________________________________
# HIL Test Automation Framework
______________________________________________________________________________________________________________________________________________________________________________________________________________________

A lightweight Python-based test automation framework designed to simulate Hardware-in-the-Loop (HIL) testing environments. It automates command frame transmission, protocol response validation, and performance reporting.

## Features

- Simulation of network protocol communication (TCP/UDP)
- Config-driven test execution using structured dictionaries/JSON configurations
- Automated test reporting with execution metrics, timing, and pass/fail status
- Extensible architecture suitable for software validation and CI pipelines

## File Structure

- `hil_test_runner.py`: Main test engine and simulation script

## How It Works

- Loads test cases containing target commands and expected outcomes.
- Opens socket connections to simulate hardware endpoints.
- Sends command frames, evaluates responses against expected criteria, and calculates execution latency.
- Outputs a detailed JSON-formatted execution report.

## How to Run

1. Install Python 3.
2. Run the framework script in your terminal:

        python3 hil_test_runner.py

## Future Improvements

- YAML/JSON external configuration file loading support
- Integration with standard testing frameworks (pytest)

## License
