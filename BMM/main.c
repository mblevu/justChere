#include "memory_manager.h"



TestScenario test_scenarios[NUM_TEST_SCENARIOS] = {
	{1048576, 128, 100},                             /*Small pool, small max block size*/
	{1024 * 1024 * 1024, 2 * 1024 * 1024, 100},      /*Large pool, large max block size*/
	{1024 * 1024 * 1024, 0, 100},                    /*Large pool, variable max block size*/
	{1048576, 0, 100},                                /*Small pool, variable max block size*/
	{1024 * 1024, 64, 1000},                          /*Medium pool, medium max block size*/
	{1048576, 1024, 100},                             /*Small pool, large max block size*/
	{1024, 512, 10},                                 /*Very small pool, medium max block size*/
	{1024 * 1024, 0, 1000},                           /*Medium pool, variable max block size*/
	{1024, 16, 10000},                                /*Very small pool, very small max block size*/
	{1024 * 1024 * 1024, 1024 * 1024, 100}           /*Large pool, same size max block size as pool*/
};


/**
 * main- Entry point of the program.
 *
 * This function initializes a memory manager, runs a series of test scenarios,
 * and frees the memory manager after each scenario.
 *
 * Return: 0 on successful execution.
 */
int main()
{
	int i;

	srand(time(NULL));

	for (i = 0; i < NUM_TEST_SCENARIOS; ++i)
	{
		MemoryManager *manager = init_memory_manager(test_scenarios[i].pool_size);

		run_test_scenario(manager, test_scenarios[i]);

		free_memory_manager(manager);
		printf("\n");
	}

	return (0);
}
