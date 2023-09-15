#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;

	// Initiate the buffer
	buffer[0] = '\0';

	// Gather input
	r = fgets(buffer, SIZE, stdin);
	if (r == NULL)
	{
		fprintf(stderr, "Input error\n");
		exit(1);
	}

	// Remove the newline
	for (int i = 0; i < SIZE; i++)
	{
		// Remove newline
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
	}

	return (buffer);
}

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

/* fill the structure */
void fill(struct item *s, int i)
{
	char temp[SIZE];

	s->id = i;
	printf("Record %d Fruit: ", i);
	strcpy(s->name, input());
	printf("Price: ");
	strcpy(temp, input());
	s->price = strtof(temp, NULL);
	/* the 'next' member is filled in the main() function */
}

/* output the list */
void output(struct item *s)
{
	while (s != NULL)
	{
		printf("%d: %s for %.2f/pound\n",
			   s->id,
			   s->name,
			   s->price);
		s = s->next;
	}
}

int main()
{
	struct item *first, *current;

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
			// Set the next structure link
			current->next = allocate();

			// Make the next structure the current structure
			current = current->next;
		}
		fill(current, i + 1);
	}

	// Cap the final structure
	current->next = NULL;

	// Output the list
	output(first);

	return (0);
}
