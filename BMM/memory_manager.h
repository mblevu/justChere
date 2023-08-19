#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include <stdint.h>


/* Define a macro for indicating memory allocation failure */
#define MEMORY_FAILURE NULL

/* Define a maximum block size for memory allocations */
#define MAX_BLOCK_SIZE 1024

/* Define the maximum number of allocation requests for each scenario */
#define MAX_NUM_REQUESTS 100



/**
 * TestScenario - Define a structure to hold the parameters of a test scenario
 * @pool_size: Size of the memory pool 
 * @max_block_size: Maximum block size for allocations
 * @num_requests: Number of allocation/deallocation requests
 */
typedef struct
{
	size_t pool_size;      
	size_t max_block_size; 
	size_t num_requests;    
} TestScenario;


/**
 * MemoryManager - define a memory block struct
 * @memory_pool: pointer to the memory pool
 * @pool_size: size of the memory pool
 */
typedef struct
{
	void *memory_pool;
	size_t pool_size;
} MemoryManager;


/**
 * MemoryBlock - struct to represent each block in memory pool
 * @size: size of the memory block
 * @is_allocated: indicates whether memory block is allocated or not
*/
typedef struct MemoryBlock
{
	size_t size;
	bool is_allocated;
} MemoryBlock;



/* Function prototypes */

/* Function to initialize memory manager */
MemoryManager *init_memory_manager(size_t pool_size);

/* Function to allocate memory */
void *allocate_memory(MemoryManager *manager, size_t size);

/* Function to implement first fit algoirithm */
void *first_fit(MemoryManager *manager, size_t size);

/* Function to free memory */
void deallocate_memory(MemoryManager *manager, void *ptr);

/* Function to cleanup memory*/
void free_memory_manager(MemoryManager *manager);

/* Testing prototypes*/

/* Function to initialize test scenario */
void initialize_test_scenarios(TestScenario *scenarios);

/* simulate allocation and deallocation requests */
void run_test_scenario(MemoryManager *manager, TestScenario scenario);

/* Function to print statistics */
void print_statistics(TestScenario scenario, size_t total_allocations, size_t total_deallocations, double alloc_time, double dealloc_time,
                      size_t max_allocated_size, size_t min_allocated_size, double average_allocated_size, size_t total_failed_allocations);



#endif /* MEMORY_MANAGER_H */
