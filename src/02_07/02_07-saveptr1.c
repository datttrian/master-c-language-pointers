#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base;
	FILE *fp;

	// Allocate storage
	base = (int *)malloc(sizeof(int) * 10);
	if (base == NULL)
	{
		fprintf(stderr, "Allocation failure\n");
		exit(1);
	}

	// Fill storage
	for (int i = 0; i < 10; i++)
	{
		*(base + i) = i * 100;
	}
	puts("Memory allocated and filled");

	// Open the file
	fp = fopen("integers.dat", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to create file\n");
		exit(1);
	}

	// Save the buffer
	fwrite(base, sizeof(int), 10, fp);
	puts("Data saved");

	// Close the file
	fclose(fp);

	return (0);
}
