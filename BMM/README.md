# Bitnine Memory Manager "clone"

In this project, I have implemented a comprehensive, robust and efficient memory manager in C that has been tested with
different scenarios. Please note that this can be expanded beyond limits.

Memory Management is part of complex softwares. Memory Manager is given a fixed size
memory block called memory pool. Different modules in that software request different-sized
blocks of memory from Manager. Manager uses first-fit algorithm to get requested blocks from
memory pool. Upon finding the first-fit block from memory pool, Manager passes it to the
requesting module. When a module does not need the allocated memory anymore, the memory
block is returned to Manager so that Manager merges it back into the memory pool. This is done
so that Manager can allocate it to some other module on request.

The code in this project complies with ANSI C standard.


# Jump straight to the point
```
$ make
```
This will build bitmm and run tests. To clean up:  ```make clean```

# How to Build
# Prerequisites:

- GCC (GNU Compiler Collection): For compiling C code.
- GDB (GNU Debugger): For debugging and analyzing code.
- Valgrind: For memory analysis and leak detection (optional but recommended).
- Text Editor or IDE: For writing and editing C code.


Setting Up C Environment on Different Operating Systems:


**Linux:**


**Install GCC and GDB:**


Open a terminal.

- *Run the command*: `sudo apt-get update`
- *Install GCC*: `sudo apt-get install gcc`
- *Install GDB*: `sudo apt-get install gdb`


**Install Valgrind (Optional):**

- *Install Valgrind*: `sudo apt-get install valgrind`


Text Editor:

Popular editors include Vim, Nano, and VSCode.


**macOS:**


Install Command Line Tools:


Open Terminal.

- Run the command: `xcode-select --install`

Install Homebrew (Optional):

Homebrew simplifies package installations.

Install Homebrew: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`

**Install GCC and GDB:**

- Run: `brew install gcc gdb`

**Install Valgrind (Optional):**

- *Install Valgrind:* `brew install valgrind`


**Windows**:

- *Install MinGW-W64:* MinGW-W64 provides a native Windows port of GCC.

- Download MinGW-W64 installer from: [MinGW-W64](https://www.mingw-w64.org/downloads/)
- Choose your architecture (32-bit or 64-bit) and version.
- Install MinGW-W64 with default settings.

- *Install GDB:*

- Download GDB binaries from: [GDB for Windows](https://rpg.hamsterrepublic.com/ohrrpgce/GDB_on_Windows)
- Add the GDB folder to your system's PATH environment variable.

- *Install Valgrind (Optional):*

- Download Valgrind for Windows from: [Valgrind Windows](https://valgrind.org/downloads/current.html)
- Follow the instructions for installation.


**Open the terminal in the code directory.**

- *Compile using GCC*: `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o memory_manager`

- *Execution:*

*Run your program:* `./memory_manager`

`memory_manager` *on windows*


The program will execute a series of test scenarios with different pool sizes, maximum block sizes, and numbers of requests. The output will display statistics for each test scenario, including total allocations, total deallocations, average allocation time, average deallocation time, maximum allocated size, minimum allocated size, average allocated size, and total failed allocation requests.

Open the main.c file to adjust different cases as you wish.


**Debugging:**


*Debug with GDB:* `gdb ./memory_manager`

Set breakpoints, analyze variables, and execute line by line.


**Memory Analysis (Optional):**

- *Use Valgrind for memory analysis:* `valgrind ./memory_manager`



# Implementation


[**Initialize Memory Manager:**](https://github.com/kintokeanu/justChere/blob/main/BMM/initialize_memory.c)

**Input**
1. *pool size*: The size of the memory pool to be allocated.

**Flow**
1. Allocate memory for the MemoryManager structure using calloc.
2. Check if the memory allocation for the manager structure succeeded. If not, return NULL.
3. Check if the pool size is valid (not zero and not exceeding SIZE_MAX). If not, free the previously allocated memory and return NULL.
4. Allocate memory for the actual memory pool using calloc.
5. Check if the memory allocation for the memory pool succeeded. If not, free the previously allocated memory and return NULL.
6. Initialize the pool_size of the MemoryManager structure with the provided pool_size.
7. Call the initialize_first_block function to initialize the first memory block in the memory pool.
8. Return the initialized MemoryManager structure.

**Outputs**
1. A pointer to the initialized MemoryManager struct
2. NULL if initialization fails.




[**Allocate Memory:**](https://github.com/kintokeanu/justChere/blob/main/BMM/allocate_memory.c)


**Inputs**
1. *manager***: A pointer to the MemoryManager object that manages the memory pool.
2. *size*: The size of the memory to be allocated.

**Flow**
1. Check for invalid inputs: If manager is NULL or size is 0, return NULL.
2. Check if there is enough space in the memory pool: If size + sizeof(MemoryBlock) is greater than manager->pool_size, return NULL.
3. Use the first fit algorithm to find an available block in the memory pool.
- If a block is found:
- Set the block as allocated.
- Update the block size.
- Calculate the remaining size of the block.
- Handle the remaining space:
- If the remaining size is less than the size of a MemoryBlock, add it to the current block.
- Otherwise, create a new block after the allocated block and update its size and allocation status.
- Update the pool size by subtracting the allocated size and the size of a MemoryBlock.
- Return a pointer to the allocated memory (skip the MemoryBlock header).
- If no block is found, return NULL.

**Outputs**
1. A pointer to the allocated memory if successful.
2. NULL if the allocation fails.



[**Deallocate Memory:**](https://github.com/kintokeanu/justChere/blob/main/BMM/deallocate_memory.c)

**Inputs**
1. *manager:* A pointer to the MemoryManager structure that manages the allocated memory blocks.
2. *ptr:* A pointer to the memory block that needs to be deallocated.

**Flow**
1. Check if manager and ptr are not NULL using the assert function.
2. Retrieve the MemoryBlock structure associated with ptr using the get_memory_block function.
3. If the retrieved block is not within the range managed by the manager, return.
4. If the block is already deallocated, return.
5. Set the is_allocated flag of the block to false using the set_is_allocated_false function.

**Outputs**
1. None. The function does not return any value.



[**First Fit Algorithm:**](https://github.com/kintokeanu/justChere/blob/main/BMM/first_fit_algorithm.c)

**Inputs**
1. *manager*: A pointer to a MemoryManager struct that contains the memory pool and other information.
2. *size*: The requested size of the memory block to be allocated.

**Flow**
1. Check if the manager is NULL, the memory pool is NULL, the requested size is 0, or the requested size is greater than the pool size. If any of these conditions are true, return NULL.
2. Calculate the end address of the memory pool.
3. Set the current block pointer to the start of the memory pool.
4. Check if the current block is NULL. If so, return NULL.
5. Iterate through the memory blocks in the memory pool until the end address is reached.
6. If the current block is not allocated and its size is greater than or equal to the requested size:
- If the remaining size after allocating the requested size is large enough to accommodate a new block, split the current block into two blocks.
- Set the size and allocation status of the current block and the new block.
- Return a pointer to the data part of the new block.
- Otherwise, set the allocation status of the current block and return a pointer to the data part of the current block.
7. Move the current block pointer to the next block by adding the size of the current block and the overhead to the current block pointer.
8. If no suitable memory block is found, return NULL.

**Outputs**
1. A pointer to the first available memory block that can accommodate the requested size, or NULL if no suitable block is found.

![First fit algorithm](images/firstfit_algorithm.png)

To use the best_fit algorithm for memory allocation, you can replace the corresponding parts in [**Allocate Memory:**](https://github.com/kintokeanu/justChere/blob/main/BMM/allocate_memory.c)
function with the following:

`block = best_fit(manager, block_size);`

This way, you'll be able to compare the results of the first_fit and best_fit algorithms by running your test scenarios. Keep in mind that the performance and behavior of different memory allocation strategies can vary depending on the specific use case and memory allocation patterns.


[**Run Test Scenario:**](https://github.com/kintokeanu/justChere/blob/main/BMM/test_bed.c)

**Inputs**
1. *manager*: A pointer to the memory manager.
2. *scenario*: The test scenario containing the number of requests and the maximum block size.

**Flow**
1. Initialize variables to keep track of statistics.
2. Seed the random number generator.
3. Initialize the allocation_pointers array.
4. Iterate over the specified number of requests.
5. Determine the block size based on the maximum block size in the scenario.
6. Allocate memory if the block size is greater than 0.
7. Update statistics based on allocation success or failure.
8. Deallocate all allocated pointers.
9. Calculate the average allocated size.
10. Print the statistics for the current test scenario.

**Outputs**
1. Statistics for the current test scenario, including total allocations, total deallocations, allocation time, deallocation time, max allocated size, min allocated size, average allocated size, and total failed allocations.



[**Free Memory Manager:**](https://github.com/kintokeanu/justChere/blob/main/BMM/free_memory.c)

**Inputs**
1. *manager*: A pointer to a MemoryManager object.

**Flow**
1. Check if the manager pointer is NULL.
2. If the manager pointer is NULL, return without doing anything.
3. Free the memory pool associated with the manager by calling free() on manager->memory_pool.
4. Free the manager object itself by calling free() on manager.

**Outputs**
1. None. The function does not return any value.



![Flow](images/flowchart.png)


# Interpreting Output Statistics:


The output statistics provide insights into how the memory manager performs under various scenarios.

*Here's how to interpret the key statistics:*

- *Pool size*: The size of the memory pool used for allocations.
- *Max block size*: The maximum size of a memory block that can be allocated.
- *Total allocations*: The total number of successful memory allocations.
- *Total deallocations*: The total number of memory deallocations.
- *Average allocation time*: The average time taken for successful memory allocations (in seconds).
- *Average deallocation time*: The average time taken for memory deallocations (in seconds).
- *Maximum allocated size*: The largest size of memory block allocated.
- *Minimum allocated size*: The smallest size of memory block allocated.
- *Average allocated size*: The average size of memory blocks allocated.
- *Total failed allocation requests*: The total number of allocation requests that failed due to insufficient space.


# Example:


Test scenario
- Pool size: 1048576, Max block size: 128
- Total allocations: 100
- Total deallocations: 1
- Average allocation time: 0.000004 seconds
- Average deallocation time: 0.000003 seconds
- Maximum allocated size: 140 bytes
- Minimum allocated size: 2 bytes
- Average allocated size: 61.67 bytes
- Total failed allocation requests: 0


In this example, the program executed a test scenario with a *pool size of 1048576 bytes* and a *maximum block size of 128 bytes*. It performed *100 successful allocations* and *1 deallocation*. The *average allocation time was 0.000004 seconds*, and the *average deallocation time was 0.000003 seconds* which is pretty quick. The *maximum allocated size was 140 bytes*, the *minimum allocated size was 2 bytes*, and the *average allocated size was 61.67 bytes*. There were no failed allocation requests.

Another case where all allocations will be deallocated

Test scenario
- Pool size: 1048576, Max block size: 128
- Total allocations: 100, - Total deallocations: 100
- Average allocation time: 0.000003 seconds
- Average deallocation time: 0.000003 seconds
- Maximum allocated size: 144 bytes
- Minimum allocated size: 3 bytes
- Average allocated size: 69.21 bytes
- Total failed allocation requests: 0

In this It performed *100 successful allocations* and *100 deallocation*.


# Design


**Design Overview:**


- The memory manager is designed to efficiently allocate and deallocate blocks of memory from a fixed-size memory pool.
- The key goals of the design include;
    - minimizing fragmentation
    - providing fast allocation and deallocation
    - accommodating different block sizes.


**Memory Pool:**


- A memory pool is created using a contiguous block of memory.
- This pool serves as the source of memory for allocations.
- The pool is divided into Memory Blocks, where each block is preceded by a metadata structure (MemoryBlock).
- The metadata helps in keeping track of whether a block is allocated or free.


# Structure:

**MemoryBlock Struct**

MemoryBlock is a struct that represents each block in the memory pool, with fields for the size of the memory block and whether it is allocated or not.

- *size*: The size of the memory block.
- *is_allocated*: A flag indicating whether the block is currently allocated or free.


**MemoryManager Struct:**

 MemoryManager is used to define a memory block struct, which includes a pointer to the memory pool and the size of the memory pool. 


+ *memory_pool*: A pointer to the memory pool.
+ *pool_size*: The total size of the memory pool.

**TestScenario Struct:**

TestScenario is used to hold the parameters of a test scenario, including the size of the memory pool, the maximum block size for allocations, and the number of allocation/deallocation requests.

# Algorithms:


**Allocation Algorithm (First Fit):**

- The First Fit algorithm is employed for allocating memory blocks.
- When an allocation request is made, the memory manager searches for the first available free block that can accommodate the requested size.
- This minimizes fragmentation and helps in efficient utilization of memory.
![First fit algorithm](images/firstfit.png)

Here are some observations from the results from both the best_fit and first_fit algorithms for different test scenarios.:

1. *Average Allocation Time*: The average allocation time for both algorithms is very low in most cases, which is a good indication of efficient memory allocation.

2. *Average Deallocation Time*: The average deallocation time is also low for both algorithms, suggesting efficient memory deallocation.

3. *Maximum Allocated Size*: The maximum allocated size varies between scenarios and algorithms. It's expected that the maximum allocated size is close to the specified maximum block size in the scenarios.

4. *Minimum Allocated Size*: The minimum allocated size also varies. It should be at least the size of a memory block header.

5. *Average Allocated Size*: The average allocated size varies between scenarios and algorithms. It should reflect the overall average size of allocations.

6. *Total Failed Allocation Requests*: It's great to see that there are no failed allocation requests in the provided results. Both algorithms seem to be able to allocate memory without issues.


**Deallocation Algorithm:**

- Deallocating memory involves marking a MemoryBlock as free.
- This allows previously allocated blocks to be reused for future allocations, reducing fragmentation.


# Data Structures:


- *Memory Pool*: A contiguous block of memory used for allocations and deallocations.

- *MemoryBlock Structure*: Each block in the memory pool contains metadata (MemoryBlock structure) that helps in tracking block status and size.


# Rationale for Design Choices:


- *Memory Pool*: Using a pre-allocated memory pool reduces the overhead of frequent system calls to allocate and deallocate memory. This improves overall efficiency and reduces memory fragmentation.

- *First Fit Allocation*: The First Fit algorithm is simple and fast, making it a good choice for this implementation. It balances between allocating the requested size and minimizing fragmentation.

- *Best Fit Allocation*: This is a reliable algorthm too but a bit complex but ive implemented it just incase.

- *MemoryBlock Metadata*: The inclusion of metadata before each memory block helps in efficiently managing and tracking block status. This metadata is crucial for accurate deallocation and future allocations.



# Conclusion:


The memory manager's design is focused on achieving efficient memory utilization, fast allocation, and accurate deallocation. By using a memory pool and the First Fit algorithm, the memory manager optimizes memory usage and reduces fragmentation. The use of MemoryBlock metadata ensures effective tracking of block status and size, contributing to the overall robustness of the system. This design provides a strong foundation for managing memory in resource-constrained environments.

