#include "memory_manager.h"



/**
 * get_pool_size - Retrieves the pool size from the given TestScenario object.
 *
 * @scenario: The TestScenario object from which to retrieve the pool size.
 * Return: The pool size as a size_t value.
 */
size_t get_pool_size(TestScenario scenario)
{
	return (scenario.pool_size);
}

/**
 * get_max_block_size - Retrieves the maximum block size from the given test scenario.
 *
 * @scenario: The test scenario object.
 * Return: The maximum block size.
 */
size_t get_max_block_size(TestScenario scenario)
{
    return (scenario.max_block_size);
}

/**
 * print_statistics - Prints the statistics of a test scenario.
 *
 * This function prints the details of the test scenario, including the pool size and maximum block size.
 * It also prints the total number of allocations and deallocations made in the test scenario.
 * If there were any allocations made, it calculates and prints the average allocation time.
 * If there were any deallocations made, it calculates and prints the average deallocation time.
 * Additionally, it prints the maximum and minimum sizes of memory allocated in the test scenario,
 * the average size of memory allocated, and the total number of failed allocation requests.
 *
 * @scenario: The test scenario object.
 * @total_allocations: The total number of allocations made in the test scenario.
 * @total_deallocations: The total number of deallocations made in the test scenario.
 * @alloc_time: The total time taken for all allocations in the test scenario.
 * @dealloc_time: The total time taken for all deallocations in the test scenario.
 * @max_allocated_size: The maximum size of memory allocated in the test scenario.
 * @min_allocated_size: The minimum size of memory allocated in the test scenario.
 * @average_allocated_size: The average size of memory allocated in the test scenario.
 * @total_failed_allocations: The total number of failed allocation requests in the test scenario.
 */
void print_statistics(TestScenario scenario, size_t total_allocations, size_t total_deallocations, double alloc_time, double dealloc_time,
			size_t max_allocated_size, size_t min_allocated_size, double average_allocated_size, size_t total_failed_allocations)
{
	/*Print test scenario details*/
	printf("Test scenario\n- Pool size: %lu, Max block size: %lu\n", get_pool_size(scenario), get_max_block_size(scenario));

	/*Print allocation and deallocation details*/
	printf("- Total allocations: %lu, - Total deallocations: %lu\n", total_allocations, total_deallocations);

	/*Print average allocation time*/
	if (total_allocations != 0)
	{
		printf("- Average allocation time: %.6f seconds\n", alloc_time / total_allocations);
	}
	else
	{
		printf("- Average allocation time: N/A\n");
	}

	/*Print average deallocation time*/
	if (total_deallocations != 0)
	{
		printf("- Average deallocation time: %.6f seconds\n", dealloc_time / total_deallocations);
	}
	else
	{
		printf("- Average deallocation time: N/A\n");
	}

	/*Print maximum and minimum allocated sizes*/
	printf("- Maximum allocated size: %lu bytes\n", max_allocated_size);
	printf("- Minimum allocated size: %lu bytes\n", min_allocated_size);

	/*Print average allocated size*/
	printf("- Average allocated size: %.2f bytes\n", average_allocated_size);

	/*Print total failed allocation requests*/
	printf("- Total failed allocation requests: %lu\n", total_failed_allocations);
}
