#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base, *p;

	// Allocate storage
	base = (int *)malloc(sizeof(int) * 10);
	if (base == NULL)
	{
		fprintf(stderr, "Allocation failure\n");
		exit(1);
	}

	// Retain the base
	p = base;

	// Fill storage
	for (int i = 0; i < 10; i++)
	{
		*p = i * 100;
		// Reference the next integer location
		p++;
	}
	puts("Memory allocated and filled");

	// Output the buffer's contents
	p = base;
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *p);
		p++;
	}

	return (0);
}
