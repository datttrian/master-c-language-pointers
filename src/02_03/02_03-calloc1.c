#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;

	// The calloc() function allocates and initializes storage to all zeros or all null characters in a char buffer
	storage = (int *)calloc(5, sizeof(int));
	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");

	// The pointer is allocated, and the storage locations are initialized to zero
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(storage + i));

	return (0);
}
