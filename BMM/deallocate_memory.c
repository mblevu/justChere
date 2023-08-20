#include "memory_manager.h"

/**
 * deallocate_memory - Deallocates a memory block that was previously
 * allocated by the MemoryManager.
 * @manager: A pointer to the MemoryManager structure that manages
 * the allocated memory blocks
 * @ptr: A pointer to the memory block that needs to be deallocated.
 * Return: void
*/

void deallocate_memory(MemoryManager *manager, void *ptr)
{
	MemoryBlock *block;
	assert(manager != NULL && ptr != NULL);

	block = get_memory_block(ptr);
	
	if (!is_block_in_range(manager, block))
	{
		return;
	}

	if (!is_block_allocated(manager, ptr))
	{
		return;
	}

	set_is_allocated_false(block);
}
