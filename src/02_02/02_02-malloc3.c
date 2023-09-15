#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int size = 5;

	storage = (int *)malloc(sizeof(int) * size);
	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	else
	{
		printf("Memory allocated for %d integers\n", size);
	}

	return (0);
}
