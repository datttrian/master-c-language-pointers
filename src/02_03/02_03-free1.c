#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;

	// The malloc() function allocates the pointer
	storage = (int *)malloc(sizeof(int) * 5);
	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");

	// The pointer is allocated, but the storage locations haven't been initialized
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(storage + i));

	// Release the allocated memory
	free(storage);
	storage = NULL;
	puts("Memory freed");

	/* It's unnecessary to free() storage before a program quits, but if you plan on
	reusing the pointer, or it's allocated within a function, do free it and assign
	the pointer to the NULL symbolic constant
	*/

	return (0);
}
