#include "memory_manager.h"


/**
 * set_allocated - Sets the allocated status of a MemoryBlock object.
 * This function sets the is_allocated property of the MemoryBlock
 * object to the specified value.
 * @block: A pointer to the MemoryBlock object.
 * @allocated: A boolean value indicating whether the MemoryBlock
 * object should be allocated or not.
 * Return: void
 */

void set_allocated(MemoryBlock *block, bool allocated)
{
	if (block != NULL)
	{
		block->is_allocated = allocated;
	}
}

/**
 * set_block_size - Sets the size of a MemoryBlock object.
 * This function sets the size property of the MemoryBlock
 * object to the specified size.
 * @block: A pointer to the MemoryBlock object.
 * @size: The size value that needs to be set for the MemoryBlock object.
 * Return: void
 */

void set_block_size(MemoryBlock *block, size_t size)
{
	if (block != NULL)
	{
		block->size = size;
	}
}
