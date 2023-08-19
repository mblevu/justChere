#include "memory_manager.h"


/**
 * free_memory_manager - Frees the memory allocated for a MemoryManager object.
 * This function frees the memory allocated for a MemoryManager object,
 * including the memory pool associated with it.
 * If the manager pointer is NULL, the function returns
 * immediately without performing any action.
 * @manager: A pointer to the MemoryManager object to be freed.
 * Return: void
 */

void free_memory_manager(MemoryManager *manager)
{
	/*Check if the manager pointer is NULL*/
	if (manager == NULL)
	{
		return;
	}

	/*Free the memory pool associated with the manager*/
	free(manager->memory_pool);

	/*Free the manager itself*/
	free(manager);
}
