#include "memory_manager.h"


/**
 * first_fit - Finds the first available memory block in the
 * given memory manager that can accommodate the requested size.
 *
 * @manager: A pointer to a MemoryManager struct that contains
 * the memory pool and other information.
 * @size: The requested size of the memory block to be allocated.
 * Return: A pointer to the first available memory block that can
 * accommodate the requested size, or NULL if no suitable block is found.
 */

void *first_fit(MemoryManager *manager, size_t size)
{
	MemoryBlock *block = (MemoryBlock *)manager->memory_pool;

	/* iterate through memory blocks within the managers memory pool*/
	while ((char *)block < (char *)manager->memory_pool + manager->pool_size)
	{
		/* check if the block is unallocated and has sufficient size for request*/
		if (!block->is_allocated && block->size >= size)
		{
			return (block); /*return the block found*/
		}
		/*move to the next block by advancing by blocks size and overhead*/
		block = (MemoryBlock *)((char *)block + block->size + sizeof(MemoryBlock));
	}

	return (NULL); /* if no suitable block is found*/
}
