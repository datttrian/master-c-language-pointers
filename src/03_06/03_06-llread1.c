#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item
{
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc(sizeof(struct item) * 1);
	if (p == NULL)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}

	return (p);
}

/* output the list */
void output(struct item *s)
{
	while (s != NULL)
	{
		printf("%d: %s for $%.2f/pound\n",
			   s->id + 1,
			   s->name,
			   s->price);
		s = s->next;
	}
}

int main()
{
	struct item *first, *current;
	FILE *fp;

	/* open the file */
	puts("Reading data...");

	// Open the file for reading
	fp = fopen("lldata.dat", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		exit(1);
	}

	// The list has five items
	for (int i = 0; i < 5; i++)
	{
		// Allocate initial structure
		if (i == 0)
		{
			first = allocate();
			current = first;
		}
		else
		{
			current->next = allocate();

			// Update the pointer member, discarding the saved info
			current = current->next;
		}

		// Use fread to fill the structure
		fread(current, sizeof(struct item), 1, fp);
	}
	/* cap the final structure */
	current->next = NULL;

	/* close the file */
	fclose(fp);

	/* output the list */
	output(first);

	return (0);
}
