#include "memory_manager.h"



/**
 * initialize_first_block - Initializes the first memory block in the memory pool.
 *
 * This function takes a pointer to the memory pool and the size of the pool as input.
 * It checks if the memory pool is NULL before proceeding. If it is NULL, the function returns NULL.
 *
 * The function then assigns the memory block to the first block in the memory pool.
 *
 * It checks if the pool size is greater than the size of the memory block before assigning the size.
 * If it is, the function subtracts the size of the memory block from the pool size and assigns it to the first block's size.
 * If the pool size is not greater than the size of the memory block, the function assigns 0 to the first block's size.
 *
 * After assigning the size, the function checks if the size is valid.
 * If the size is 0 or greater than SIZE_MAX, the function returns NULL.
 *
 * Finally, the function sets the is_allocated flag of the first block to false and returns the first block.
 *
 * @memory_pool: A pointer to the memory pool.
 * @pool_size: The size of the memory pool.
 * Return: The initialized first memory block, or NULL if the memory pool is NULL or the size is invalid.
 */
MemoryBlock *initialize_first_block(void *memory_pool, size_t pool_size)
{
	MemoryBlock *first_block;

	/* Check if memory_pool is NULL before proceeding*/
	if (memory_pool == NULL)
	{
		return (NULL);
	}

	first_block = (MemoryBlock *)memory_pool;

	/*Check if pool_size is greater than sizeof(MemoryBlock) before assigning the size*/
	if (pool_size > sizeof(MemoryBlock))
	{
		first_block->size = pool_size - sizeof(MemoryBlock);
	}
	else
	{
		first_block->size = 0;
	}

	/*Check if the size is valid after subtraction*/
	if (first_block->size == 0 || first_block->size > SIZE_MAX)
	{
		return (NULL);
	}

	first_block->is_allocated = false;

	return (first_block);
}

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

	/* allocate memory for the MemoryManager structure */
	manager = (MemoryManager *)calloc(1, sizeof(MemoryManager));

	/* check if memory allocation for the manager structure succeeded */
	if (manager == NULL)
	{
		return (NULL);
	}

	/* check if the pool size is valid */
	if (pool_size == 0 || pool_size > SIZE_MAX)
	{
		free(manager); /* free previously allocated memory */
		return (NULL); /* return null as pool size is invalid */
	}

	/* allocate memory for the actual memory pool */
	manager->memory_pool = calloc(pool_size, 1);

	/* check if memory allocation for the memory pool succeeded */
	if (manager->memory_pool == NULL)
	{
		free(manager);  /* free previously allocated memory */
		return (NULL); /* if memory pool allocation failed */
	}

	/* initialize managers pool_size with provided pool_size */
	manager->pool_size = pool_size;

	/**
	 * initialize the first block as the entire
	 * pool minus the size of the MemoryBlock overhead
	 */
	initialize_first_block(manager->memory_pool, pool_size);

	return (manager); /* initialized MemoryManager */
}
