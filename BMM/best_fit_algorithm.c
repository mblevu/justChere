#include "memory_manager.h"


/**
 * best_fit - Allocates memory from a memory pool using the best fit algorithm.
 * It searches for the smallest available memory block that can accommodate the requested size and returns a pointer to that block.
 * If there is enough remaining space in the block, it splits the block into two, with one part allocated and the other part remaining free.
 *
 * @manager: A pointer to the MemoryManager struct which contains information about the memory pool.
 * @size: The size of the memory block to be allocated.
 * Return: A pointer to the allocated memory block, or NULL if no suitable block is found.
 */
void *best_fit(MemoryManager *manager, size_t size)
{
	char *pool_end;
	MemoryBlock *current_block;
	MemoryBlock *best_fit_block = NULL;
	size_t min_remaining_size = SIZE_MAX;

	if (manager == NULL || manager->memory_pool == NULL || size == 0 || size > manager->pool_size)
	{
		return (NULL);
	}

	pool_end = (char *)manager->memory_pool + manager->pool_size;
	current_block = (MemoryBlock *)manager->memory_pool;

	while ((char *)current_block < pool_end)
	{
		if (!current_block->is_allocated && current_block->size >= size)
		{
			size_t remaining_size = current_block->size - size;

			if (remaining_size < min_remaining_size)
			{
				best_fit_block = current_block;
				min_remaining_size = remaining_size;
			}
		}
		current_block = (MemoryBlock *)((char *)current_block + current_block->size + BLOCK_OVERHEAD);
	}

	if (best_fit_block != NULL)
	{
		best_fit_block->is_allocated = true;
		/* Handle splitting blocks if remaining space is sufficient */
		if (min_remaining_size >= sizeof(MemoryBlock))
		{
			MemoryBlock *new_block = (MemoryBlock *)((char *)best_fit_block + size + BLOCK_OVERHEAD);

			set_block_size(new_block, min_remaining_size - BLOCK_OVERHEAD);
			set_allocated(new_block, false);
			set_block_size(best_fit_block, size);
		}
		return ((void *)(best_fit_block + 1));
	}

	return (NULL);
}
