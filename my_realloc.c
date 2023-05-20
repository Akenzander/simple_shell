#include "shell.h"

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
