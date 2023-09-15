#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base, x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc(sizeof(int) * 10);
	if (base == NULL)
	{
		fprintf(stderr, "Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for (x = 0; x < 10; x++)
	{
		*(base + x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* open the file */
	fp = fopen("integers.dat", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to create file\n");
		exit(1);
	}

	/* save the buffer */
	fwrite(base, sizeof(base), 1, fp);
	puts("Data saved");

	/* close the file */
	fclose(fp);

	return (0);
}
