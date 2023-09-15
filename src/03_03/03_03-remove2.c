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
	struct item *first, *current, *temp;
	int x;

	/* build a linked list with 5 items */
	for (x = 0; x < 5; x++)
	{
		/* allocate initial structure */
		if (x == 0)
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current, x);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	output(first);

	/* remove the fourth structure from the list */
	puts("Removing the fourth record:");
	current = first;
	/* locate the third structure to remove
	   the fourth */
	while (current->id != 3)
	{
		current = current->next;
		/* always test with pointers! */
		if (current == NULL)
		{
			fprintf(stderr, "Structure out of bounds\n");
			exit(1);
		}
	}

	// Save the current->next pointer
	temp = current->next;

	// Refocus the next pointer to reference structure 4 instead of 3
	current->next = temp->next;

	// Free the storage
	free(temp);

	// Output the updated list
	output(first);

	return (0);
}
