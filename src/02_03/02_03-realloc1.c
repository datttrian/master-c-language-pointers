#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;

	// Use malloc to set the buffer size to store five integers
	storage = (int *)malloc(sizeof(int) * 5);
	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");

	// Initialize and output the values
	for (int i = 0; i < 5; i++)
	{
		*(storage + i) = (i + 1) * 11;
		printf("%d\n", *(storage + i));
	}

	// Now increase the buffer size by two integer values
	storage = (int *)realloc(storage, sizeof(int) * 7);
	if (storage == NULL)
	{
		fprintf(stderr, "Reallocation failed\n");
		exit(1);
	}
	puts("Buffer re-sized");

	// Add the final two values
	*(storage + 5) = 66;
	*(storage + 6) = 77;

	// Output the result
	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", *(storage + i));
	}

	return (0);
}
