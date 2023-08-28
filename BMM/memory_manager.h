#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

/* libraries used */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>


/* defines a block overhead for memory block */
#define BLOCK_OVERHEAD sizeof(MemoryBlock)

/* Define a macro for indicating memory allocation failure */
#define MEMORY_FAILURE NULL

/* Define a maximum block size for memory allocations */
#define MAX_BLOCK_SIZE 1024

/* Define the maximum number of allocation requests for each scenario */
#define MAX_NUM_REQUESTS 100

/* number of test scenarios */
#define NUM_TEST_SCENARIOS 10


#define SPECIAL_VALUE NULL


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



/**
 * Function prototypes/Main API(s)
 */

/* Function to initialize memory manager */
MemoryManager *init_memory_manager(size_t pool_size);

/* Function to allocate memory */
void *allocate_memory(MemoryManager *manager, size_t size);

/* Function to free/deallocate memory */
void deallocate_memory(MemoryManager *manager, void *ptr);

/* Function to cleanup memory*/
void free_memory_manager(MemoryManager *manager);


/* Helper functions for allocating and deallocating memory */


/* Function to initialize first memory block */
MemoryBlock *initialize_first_block(void *memory_pool, size_t pool_size);
/* Function to implement first fit algoirithm */
void *first_fit(MemoryManager *manager, size_t size);
/* Function to implement best_fit algorithm */
void *best_fit(MemoryManager *manager, size_t size);
/*Retrieves the memory block associated with a given pointer*/
MemoryBlock *get_memory_block(void *ptr);
/*Checks if a memory block is within the range of a memory manager*/
bool is_block_in_range(MemoryManager *manager, MemoryBlock *block);
/*Checks if a memory block is allocated.*/
bool is_block_allocated(MemoryManager *manager, void *ptr);
/*Sets the "is_allocated" flag of a memory block to false*/
void set_is_allocated_false(MemoryBlock *block);


/**
 * setter functions 
 */

/* setter function to set is_allocated field of a MemoryBlock*/
void set_allocated(MemoryBlock *block, bool allocated);
/* setter function to set size field of a MemoryBlock */
void set_block_size(MemoryBlock *block, size_t size);


/**
 * getter functions
*/

/* Retrieves the pool size from the given TestScenario object */
size_t get_pool_size(TestScenario scenario);
/*Retrieves the maximum block size from the given test scenario*/
size_t get_max_block_size(TestScenario scenario);


/**
 * Testing function prototypes
 */

/* Function to initialize test scenario */
void initialize_test_scenarios(TestScenario *scenarios);
/* simulate allocation and deallocation requests */
void run_test_scenario(MemoryManager *manager, TestScenario scenario);
/* Function to print statistics */
void print_statistics(TestScenario scenario, size_t total_allocations, size_t total_deallocations, double alloc_time, double dealloc_time,
                      size_t max_allocated_size, size_t min_allocated_size, double average_allocated_size, size_t total_failed_allocations);


#endif /* MEMORY_MANAGER_H */
