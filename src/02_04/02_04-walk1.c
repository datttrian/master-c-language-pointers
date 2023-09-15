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
		*p = i * 100;
		/* reference the next integer location */
		p++;
	}
	puts("Memory allocated and filled");

	return (0);
}
