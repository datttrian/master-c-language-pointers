#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *storage;

	storage = (char *)malloc(sizeof(char) * 16);
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
