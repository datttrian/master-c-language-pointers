#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* 15 characters are required for input */
	char *input;

	input = (char *)malloc(sizeof(char) * 15 + 1);
	if (input == NULL)
	{
		fprintf(stderr, "Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("15 characters are available for input");
	}

	return (0);
}
