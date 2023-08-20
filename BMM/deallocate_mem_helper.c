#include "memory_manager.h"


/**
 * get_memory_block - Retrieves the memory block associated with a given pointer.
 *
 * @ptr: The pointer to the memory block.
 * Return: The memory block associated with the given pointer.
 */
MemoryBlock *get_memory_block(void *ptr)
{
    return ((MemoryBlock *)((char *)ptr - sizeof(MemoryBlock)));
}

/**
 * is_block_in_range - Checks if a memory block is within the range of a memory manager.
 *
 * @manager: The memory manager.
 * @block: The memory block to check.
 * Return: True if the memory block is within the range of the memory manager, false otherwise.
 */
bool is_block_in_range(MemoryManager *manager, MemoryBlock *block)
{
    return block >= (MemoryBlock *)manager->memory_pool &&
           block < (MemoryBlock *)((char *)manager->memory_pool + manager->pool_size);
}

/**
 * is_block_allocated - Checks if a memory block is allocated.
 *
 * @manager: The memory manager.
 * @ptr: The pointer to the memory block.
 * Return: True if the memory block is allocated, false otherwise.
 */
bool is_block_allocated(MemoryManager *manager, void *ptr)
{
    MemoryBlock *block;

    if (manager == NULL || ptr == NULL)
    {
        return false;
    }

    block = (MemoryBlock *)((char *)ptr - sizeof(MemoryBlock));

    if (block < (MemoryBlock *)manager->memory_pool ||
        block >= (MemoryBlock *) ((char *)manager->memory_pool + manager->pool_size))
    {
        return false;
    }

    return block->is_allocated;
}

/**
 * set_is_allocated_false - Sets the "is_allocated" flag of a memory block to false.
 *
 * @block: The memory block.
 * Return; void
 */
void set_is_allocated_false(MemoryBlock *block)
{
    block->is_allocated = false;
}
