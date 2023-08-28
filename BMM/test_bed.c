#include "memory_manager.h"


/**
 * run_test_scenario - This function runs a test scenario for a memory manager.
 *
 * The function takes a MemoryManager object and a TestScenario object as parameters.
 * It initializes variables to keep track of various statistics related to memory
 * allocation and deallocation.
 * It then iterates over a specified number of requests, randomly determining the
 * block size and allocating memory if the block size is greater than 0.
 * It updates the statistics based on the success or failure of the allocation.
 * After the allocations, it randomly selects a pointer from the allocated
 * pointers array and deallocates the memory.
 * Finally, it calculates the average allocated size and prints the statistics
 * for the current test scenario.
 *
 * @manager: A pointer to a MemoryManager object.
 * @scenario: A TestScenario object that specifies the number of requests and the maximum block size.
 *
 * Return: None.
 */
void run_test_scenario(MemoryManager *manager, TestScenario scenario)
{
	/* Initialize variables to keep track of various statistics */
	size_t total_allocations = 0;
	size_t total_deallocations = 0;
	clock_t start, end;
	double alloc_time = 0.0;
	double dealloc_time = 0.0;
	size_t block_size;
	void *ptr;
	void *allocation_pointers[MAX_NUM_REQUESTS];
	/*size_t random_index;*/
	size_t max_allocated_size = 0;
	size_t min_allocated_size = SIZE_MAX;
	size_t total_failed_allocations = 0;
	size_t total_allocated_size = 0;
	double average_allocated_size = 0;
	size_t i;
	size_t allocated_size;

	/* Seed the random number generator */
	srand(time(NULL));

	/* Intialize the allocation_pointers array */
	for (i = 0; i < MAX_NUM_REQUESTS; ++i)
	{
		allocation_pointers[i] = NULL;
	}

	/* Iterate over the specified number of requests */
	for (i = 0; i < scenario.num_requests; ++i)
	{
		/* Determine block size based on scenarios max_block_size */
		if (scenario.max_block_size == 0)
		{
			block_size = 0;
		}
		else
		{
			block_size = rand() % scenario.max_block_size + 1;
		}

		/* Allocate memory if block size is greater than 0 */
		if (block_size > 0)
		{
			start = clock();
			ptr = allocate_memory(manager, block_size);
			end = clock();
		}

		/* Update statistics based on allocation success or failure */
		if (ptr != NULL)
		{
			total_allocations++;
			alloc_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			allocation_pointers[total_allocations - 1] = ptr;

			/* Calculate allocated size and update max/min values */
			allocated_size = block_size + sizeof(MemoryBlock);

			if (allocated_size > max_allocated_size)
			{
				max_allocated_size = allocated_size;
			}

			if (block_size < min_allocated_size)
			{
				min_allocated_size = block_size;
			}
			total_allocated_size += block_size;
		}
		else
		{
			total_failed_allocations++;
		}
	}

	/* Deallocate all allocated pointers */
	for (i = 0; i < total_allocations; ++i)
	{
		if (allocation_pointers[i] != NULL)
		{
			start = clock();
			deallocate_memory(manager, allocation_pointers[i]);
			end = clock();
			total_deallocations++;
			dealloc_time += ((double) (end - start)) / CLOCKS_PER_SEC;
		}
	}

	/* Calculate average allocated size (avoid division by zero) */
	if (total_allocations > 0)
	{
		average_allocated_size = (double) total_allocated_size / total_allocations;
	}

	/* Print stats for the current test scenario */
	print_statistics(scenario, total_allocations, total_deallocations, alloc_time, dealloc_time, max_allocated_size,
			min_allocated_size, average_allocated_size, total_failed_allocations);
}
