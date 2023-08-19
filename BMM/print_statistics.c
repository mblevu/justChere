#include "memory_manager.h"



/**
 * print_statistics - Prints statistics related to memory allocation and deallocation.
 *
 * @scenario: The test scenario object containing information about
 * the pool size and maximum block size.
 * @total_allocations: The total number of memory allocations.
 * @total_deallocations: The total number of memory deallocations.
 * @alloc_time: The total time taken for memory allocations.
 * @dealloc_time: The total time taken for memory deallocations.
 * @max_allocated_size: The maximum size of memory allocated.
 * @min_allocated_size: The minimum size of memory allocated.
 * @average_allocated_size: The average size of memory allocated.
 * @total_failed_allocations: The total number of failed allocation requests.
 */

void print_statistics(TestScenario scenario, size_t total_allocations, size_t total_deallocations, double alloc_time, double dealloc_time,
                      size_t max_allocated_size, size_t min_allocated_size, double average_allocated_size, size_t total_failed_allocations)
{
    printf("Test scenario\n- Pool size: %lu, Max block size: %lu\n", scenario.pool_size, scenario.max_block_size);
    printf("- Total allocations: %lu\n- Total deallocations: %lu\n", total_allocations, total_deallocations);
    printf("- Average allocation time: %.6f seconds\n", alloc_time / total_allocations);
    printf("- Average deallocation time: %.6f seconds\n", dealloc_time / total_deallocations);
    printf("- Maximum allocated size: %lu bytes\n", max_allocated_size);
    printf("- Minimum allocated size: %lu bytes\n", min_allocated_size);
    printf("- Average allocated size: %.2f bytes\n", average_allocated_size);
    printf("- Total failed allocation requests: %lu\n\n", total_failed_allocations);
}
