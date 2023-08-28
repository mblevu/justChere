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
	char *pool_end;
	MemoryBlock *current_block;
	MemoryBlock *new_block;

	if (manager == NULL || manager->memory_pool == NULL || size == 0 || size > manager->pool_size)
	{
		return (NULL);
	}

	pool_end = (char *)manager->memory_pool + manager->pool_size;
	current_block = (MemoryBlock *)manager->memory_pool;

	if (current_block == NULL)
	{
		return (NULL);
	}

	while ((char *)current_block < pool_end)
		{
		/*Handle small memory requests by splitting blocks*/
		if (!current_block->is_allocated)
		{
			if (current_block->size >= size)
			{
				if (current_block->size - size >= BLOCK_OVERHEAD + sizeof(MemoryBlock))
				{
					new_block = (MemoryBlock *)((char *)current_block + size + BLOCK_OVERHEAD);

					set_block_size(new_block, current_block->size - size - BLOCK_OVERHEAD);
					set_allocated(new_block, false);
					set_block_size(current_block, size);
					set_allocated(current_block, true);
					/*Return the data part of the MemoryBlock*/
					return ((void *)(new_block + 1));
				}
				else
				{
					set_allocated(current_block, true);
					/* Return the data part of the MemoryBlock*/
					return ((void *)(current_block + 1));
				}
			}
		}
		current_block = (MemoryBlock *)((char *)current_block + current_block->size + BLOCK_OVERHEAD);
	}

	return (NULL);
}
