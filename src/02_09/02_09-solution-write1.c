#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct human
	{
		char name[32];
		int age;
	} *towrite;
	const char filename[] = "saved.dat";
	char *r;
	FILE *fp;

	// Allocate structure
	towrite = (struct human *)malloc(sizeof(struct human) * 1);
	if (towrite == NULL)
	{
		fprintf(stderr, "Unable to allocate structure memory\n");
		exit(1);
	}

	// Fill the towrite structure; prompt the user
	printf("Enter your name: ");
	r = fgets(towrite->name, 32, stdin);

	// Check for input error
	if (r == NULL)
	{
		fprintf(stderr, "Input error\n");
		exit(1);
	}

	printf("How old are you: ");

	// towrite->age is an integer, not a pointer, so the ampersand is required
	scanf("%d", &towrite->age);

	// Write the structure to a file
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to create %s\n", filename);
		exit(1);
	}											  // open the file
	fwrite(towrite, sizeof(struct human), 1, fp); // write the structure
	fclose(fp);									  // close the file

	printf("Data written to %s\n", filename);

	return (0);
}
