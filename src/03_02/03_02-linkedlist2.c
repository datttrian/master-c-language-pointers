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

// Read standard input, discard newline
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

// Allocate a new structure
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

// Fill the structure
void fill(struct item *s, int i)
{
	char temp[SIZE];

	s->id = i;
	printf("Record %d Fruit: ", i);
	strcpy(s->name, input());
	printf("Price: ");
	strcpy(temp, input());
	s->price = strtof(temp, NULL); // the 'next' member is filled in the main() function
}

// Output the list
void output(struct item *s)
{
	while (s != NULL)
	{
		printf("%d: %s for %.2f/pound\n", s->id, s->name, s->price);
		s = s->next;
	}
}

int main()
{
	struct item *first, *current;

	// Allocate initial structure
	first = allocate();

	// The base structure is now the current structure
	current = first;

	// Fill structure
	fill(current, 1);

	// Cap the final structure
	current->next = NULL;

	// Output the contents
	output(first);

	return (0);
}
