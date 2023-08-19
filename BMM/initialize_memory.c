#include "memory_manager.h"

/**
 * init_memory_manager - Initializes a memory manager
 * with the specified pool size.
 * @pool_size: The size of the memory pool to be allocated.
 * Return: A pointer to the initialized MemoryManager struct,
 * or NULL if initialization fails.
 */

MemoryManager *init_memory_manager(size_t pool_size)
{
	MemoryManager *manager;
	MemoryBlock *first_block;

	/* allocate memory for the MemoryManager structure */
	manager = (MemoryManager *)malloc(sizeof(MemoryManager));

	/* check if memory allocation for the manager structure succeded*/
	if (manager == NULL)
	{
		return (NULL);
	}

	/* check if the pool size is valid */
	if (pool_size == 0)
	{
		free(manager); /*free previously allocated memory*/
		return (NULL); /*return null as pool size is invalid*/
	}

	/*allocate memory for the actual memory pool*/
	manager->memory_pool = malloc(pool_size);

	/* check if memory allocation for the memory pool succeeded*/
	if (manager->memory_pool == NULL)
	{
		free(manager);  /*free previously allocated memory*/
		return (NULL); /*if memory pool allocation failed*/
	}

	/*initialize managers pool_size with provided pool_size*/
	manager->pool_size = pool_size;

	/**
	 * initialize the first block as the entire
	 * pool minus the size of the MemoryBlock overhead
	 */
	first_block = (MemoryBlock *)manager->memory_pool;
	first_block->size = pool_size - sizeof(MemoryBlock);
	first_block->is_allocated = false;

	return (manager); /*initialized MemoryManager*/
}

