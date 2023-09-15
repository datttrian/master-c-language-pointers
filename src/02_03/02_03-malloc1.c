#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;

	storage = (int *)malloc(sizeof(int) * 5);
	if (storage == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");

	// The memory is allocated, but uninitialized values output are garbage
	for (int i = 0; i < 5; i++)
		printf("%d\n", *(storage + i));

	return (0);
}
