#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct human
	{
		char name[32];
		int age;
	} *toread;
	const char filename[] = "saved.dat";
	FILE *fp;

	// Allocate structure
	toread = (struct human *)malloc(sizeof(struct human) * 1);
	if (toread == NULL)
	{
		fprintf(stderr, "Unable to allocate structure memory\n");
		exit(1);
	}

	// Read the structure into memory
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to read from %s\n", filename);
		exit(1);
	}											// open the file
	fread(toread, sizeof(struct human), 1, fp); // read in the structure
	fclose(fp);									// close the file

	// Output results
	puts("Data read:");

	// The 'name' member probably ends in a newline
	printf("Name: %sAge: %d\n",
		   toread->name,
		   toread->age);

	return (0);
}
