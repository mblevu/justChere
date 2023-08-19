#include "memory_manager.h"

/**
 * allocate_memory - Allocates memory from a memory pool
 * managed by a MemoryManager object.
 * @manager: A pointer to the MemoryManager object that
 *  manages the memory pool.
 * @size: The size of the memory to be allocated.
 * Return: A pointer to the allocated memory if successful,
 *  or NULL if the allocation fails.
 */

void *allocate_memory(MemoryManager *manager, size_t size)
{
	MemoryBlock *block;
	MemoryBlock *next_block;
	size_t remaining_size;

	/* Check for invalid inputs */
	if (manager == NULL || size == 0)
	{
		return (NULL);
	}

	/*check if there is enough space in the memory pool*/
	if (size + sizeof(MemoryBlock) > manager->pool_size)
	{
		return (NULL);
	}

	/* use first fit algorithm to find available block*/
	block = first_fit(manager, size);

	if (block != NULL)
	{
		block->is_allocated = true;
		block->size = size; /* set size of allocated block*/
		remaining_size = block->size - size - sizeof(MemoryBlock);

		/* Create a new block if remaining space is enough for a new MemoryBlock */
		if (remaining_size >= sizeof(MemoryBlock))
		{
			next_block = (MemoryBlock *)((char *)block + sizeof(MemoryBlock) + size);
			next_block->size = remaining_size;
			next_block->is_allocated = false;

		}
		/* Return a pointer to the allocated memory (skip the MemoryBlock header) */
		return ((void *)(block + 1)); /*return pointer to allocated memory*/
	}

	return (NULL); /*allocation failed*/

}
