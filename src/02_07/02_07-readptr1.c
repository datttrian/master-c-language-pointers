#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base, r, x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc(sizeof(int) * 10);
	if (base == NULL)
	{
		fprintf(stderr, "Allocation failure\n");
		exit(1);
	}

	/* open the file */
	fp = fopen("integers.dat", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to read file\n");
		exit(1);
	}

	/* fill the buffer */
	r = fread(base, sizeof(int), 10, fp);
	/* confirm the proper data is read */
	if (r != 10)
	{
		fprintf(stderr, "File read error\n");
		exit(1);
	}
	puts("Data read");
	/* close the file */
	fclose(fp);

	/* output results */
	puts("Values:");
	for (x = 0; x < 10; x++)
	{
		printf("%d\n", *(base + x));
	}

	return (0);
}
