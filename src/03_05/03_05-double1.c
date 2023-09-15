#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

// Define structure externally to ensure that it's available to all functions
struct item
{
	int id;
	char name[SIZE];
	float price;
	struct item *next;
	struct item *previous;
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

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = {"apples", "bananas", "grapes", "strawberries", "watermelon"};
	float prices[] = {1.20, 2.58, 2.09, 2.40, 0.51};

	s->id = i;
	strcpy(s->name, fruit[i]);
	s->price = prices[i];
}

/* output the list forward */
void output_forward(struct item *s)
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

/* output the list backward */
void output_backward(struct item *s)
{
	while (s != NULL)
	{
		printf("%d: %s for $%.2f/pound\n",
			   s->id + 1,
			   s->name,
			   s->price);
		s = s->previous;
	}
}

int main()
{
	struct item *first, *last, *current, *temp;

	// Build a linked list with 5 items
	for (int i = 0; i < 5; i++)
	{
		// Allocate initial structure
		if (i == 0)
		{
			first = allocate();
			current = first;
			fill(current, i);
			current->previous = NULL;
		}
		else
		{
			// Set the next structure link
			current->next = allocate();

			// Save the current structure
			temp = current;

			// Make the next structure the current structure
			current = current->next;
			fill(current, i);
			current->previous = temp;
		}
	}

	// Cap the final structure
	current->next = NULL;

	// Set the last pointer
	last = current;

	// Output the list forward
	puts("Forward:");
	output_forward(first);

	// Output the list backward
	puts("Backward:");
	output_backward(last);

	return (0);
}
