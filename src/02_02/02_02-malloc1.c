#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *storage;

	storage = malloc(16);

	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("Memory allocated");
	}

	return (0);
}
