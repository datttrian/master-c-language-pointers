#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

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

int main()
{
	struct item
	{
		int id;
		char name[SIZE];
		float price;
		struct item *next;
	};
	struct item *first, *current;
	char temp[SIZE];

	// Allocate initial structure
	first = (struct item *)malloc(sizeof(struct item) * 1);
	if (first == NULL)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}

	// The first structure is now the current structure
	current = first;

	// Fill structure
	current->id = 1;
	printf("Record %d Fruit: ", current->id);
	strcpy(current->name, input());
	printf("Price: ");
	strcpy(temp, input());
	current->price = strtof(temp, NULL);

	// Don't forget to initialize the pointer!
	current->next = NULL;

	// Output the contents
	printf("%d: %s for %.2f/pound\n", current->id, current->name, current->price);

	return (0);
}
