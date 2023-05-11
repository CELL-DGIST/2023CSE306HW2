# 2023CSE306HW2
HW 2 for CSE306 System Programming

# PMUON Kernel Module

This is a kernel module that enables and configures the Performance Monitoring Unit (PMU) on Linux systems. 
It sets up the PMU across all cores and provides functionality to monitor performance events.
Implement your own workload in the provided skeleton code, and monitor the performance events. 

## Prerequisites

To compile and run this kernel module, ensure that you have the following:

- Linux operating system : You need the same machine where you compiled your HW1 kernel. (Virtualbox/Ubuntu)
- Kernel headers and development tools : Should be installed during HW1

## Installation

1. Clone this repository to your local machine:

   ```
   git clone https://github.com/CELL-DGIST/2023CSE306HW2.git
   ```

2. Navigate to the cloned repository:

   ```
   cd ./2023CSE306HW2
   ```

3. Complete your code(pmuon.c) and build the kernel module:

   ```
   make CROSS_COMPILE=aarch64-linux-gnu- ARCH=arm64
   ```
   
4. Copy the kernel module into your Raspberry Pi 4:
   
   Use USB or Network connection to copy pmuon.ko file into your machine.

5. Load the kernel module:

   ```
   sudo insmod pmuon.ko
   ```

6. Verify that the module has been loaded successfully:

   ```
   dmesg 
   ```

   You should see the "pmuon" module listed.
   
7. Unload the Kernel module:

   ```
   sudo rmmod pmuon
   ```


## Usage

Once the module is loaded, the PMU will be turned on and configured across all cores. You can monitor performance events using the PMU.

