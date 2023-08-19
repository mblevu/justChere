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
	/*Get the MemoryBlock structure associated with the ptr*/
	MemoryBlock *block;

	/*Check for NULL manager or ptr*/
	if (manager == NULL || ptr == NULL)
	{
		return;
	}

	/*Calculate the address of the associated MemoryBlock structure*/
	block = (MemoryBlock *)((char *)ptr - sizeof(MemoryBlock));

	/* check if the calculated block address is within the valid memory pool range*/
	if (block < (MemoryBlock *)manager->memory_pool ||
		block >= (MemoryBlock *) ((char *)manager->memory_pool + manager->pool_size))
		{
			return; /*if the block is out of range*/
		}

	/*check if the block is actually allocated*/
	if (!block->is_allocated)
	{
		return; /* if the block is not allocated */
	}

	/*Set the is_allocated flag to false, indicating memory is now deallocated*/
	block->is_allocated = false;
}
