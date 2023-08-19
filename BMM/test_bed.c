#include "memory_manager.h"



void run_test_scenario(MemoryManager *manager, TestScenario scenario)
{
	/*initialize variables to keep track of various statistics*/
	size_t total_allocations = 0;
	size_t total_deallocations = 0;
	clock_t start, end;
	double alloc_time = 0.0;
	double dealloc_time = 0.0;
	size_t block_size;
	void *ptr;
	void *allocated_ptr;
	void *allocation_pointers[MAX_NUM_REQUESTS];
	size_t random_index;
	size_t max_allocated_size = 0;
	size_t min_allocated_size = SIZE_MAX;
	size_t total_failed_allocations = 0;
	size_t total_allocated_size = 0;
	double average_allocated_size = 0;
	size_t i;
	size_t allocated_size;

	/* seed the random number generator */
	srand(time(NULL));

	/*intialize the allocation_pointers array*/
	for (i = 0; i < MAX_NUM_REQUESTS; ++i)
	{
		allocation_pointers[i] = NULL;
	}

	/*iterate over the specified number of requests */
	for (i = 0; i < scenario.num_requests; ++i)
	{
		/* determine blovk size based on scenarios max_bloack_size */
		if (scenario.max_block_size == 0)
		{
			block_size = 0;
		}
		else
		{
			block_size = rand() % scenario.max_block_size + 1;
		}

		/* allocate memory if block size is greater than 0 */
		if (block_size > 0)
		{
			start = clock();
			ptr = allocate_memory(manager, block_size);
			end = clock();
		}

		/* update statistics based on allocation success or failure */
		if (ptr != NULL)
		{
			total_allocations++;
			alloc_time += ((double) (end - start)) / CLOCKS_PER_SEC;
			allocation_pointers[total_allocations - 1] = ptr;

			/* calculate allocated size and update max/min values */
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

	/*perform deallocations for a randomly selected pointer */
	if (total_allocations > 0)
	{
		random_index = rand() % total_allocations;
		allocated_ptr = allocation_pointers[random_index];
	}

	/* deallocate memory and update deallocation statistics*/
	if (allocated_ptr != NULL)
	{
		start = clock();
		deallocate_memory(manager, allocated_ptr);
		end = clock();
		total_deallocations++;
		dealloc_time += ((double) (end - start)) / CLOCKS_PER_SEC;
		allocated_ptr = allocation_pointers[random_index];
	}

	/* caluclate average allocated size */
	average_allocated_size = (double)total_allocated_size / total_allocations;

	/* print stats for the current test scenario */
	print_statistics(scenario, total_allocations, total_deallocations, alloc_time, dealloc_time,
        max_allocated_size, min_allocated_size, average_allocated_size, total_failed_allocations);
}
