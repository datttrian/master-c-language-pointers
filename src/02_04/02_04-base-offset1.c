#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p;

	// Allocate storage
	p = (int *)malloc(sizeof(int) * 10);
	if (p == NULL)
	{
		fprintf(stderr, "Allocation failure\n");
		exit(1);
	}

	// Fill storage
	for (int i = 0; i < 10; i++)
	{
		// Use offset; retain p
		*(p + i) = i * 100;
	}
	puts("Memory allocated and filled");

	// Output the buffer's contents
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
	}

	return (0);
}
