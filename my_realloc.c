#include "shell.h"

/**
 * my_realloc - A function that resizes the memory block pointed to a pointer
 * that was previously allocated to the variable by malloc
 * @ptr: A pointer to a memory block previously allocated with malloc
 * @newsize: The new size for the memory block
 *
 * Return: A pointer to the newly allocated memory
 */

void *my_realloc(void *ptr, size_t newsize)
{
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(newsize);
	}
	else
	{
		if (newsize == 0)
		{
			free(ptr);
			new_ptr = NULL;
		}
		else
		{
			new_ptr = malloc(newsize);
			if (new_ptr != NULL)
			{
				memcpy(new_ptr, ptr, newsize);
			}
		}
	}
	return (new_ptr);
}
