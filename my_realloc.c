#include <shell.h>

void *my_realloc(void *ptr, size_t size)
{
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	void *new_ptr = malloc(size);

	if (ptr != NULL)
	{
		memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
