#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *chunk;
	chunk = malloc(1024);

	// Always test pointer allocation
	if (chunk == NULL)
	{
		puts("Memory allocation failed!");
	}
	else
	{
		printf("1024 bytes allocated at %p\n", chunk);
		free(chunk);
	}

	return (0);
}
