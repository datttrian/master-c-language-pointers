#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
enum
{
	FALSE,
	TRUE
};
struct family
{
	char name[SIZE];
	char relationship[SIZE];
	int age;
	struct family *next;
};
char filename[] = "family.dat";

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;

	/* initialize the buffer */
	buffer[0] = '\0';

	/* gather input */
	r = fgets(buffer, SIZE, stdin);
	if (r == NULL)
	{
		fprintf(stderr, "Input error\n");
		exit(1);
	}

	/* remove the newline */
	for (int i = 0; i < SIZE; i++)
	{
		/* remove newline */
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
	}

	return (buffer);
}

// Allocate a new structure
struct family *allocate(void)
{
	struct family *p;

	p = (struct family *)malloc(sizeof(struct family) * 1);
	if (p == NULL)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}

	return (p);
}

// Fill the structure
void fill(struct family *s)
{
	char temp[SIZE];

	printf("Name: ");
	strcpy(s->name, input());
	printf("Relationship: ");
	strcpy(s->relationship, input());
	printf("Age: ");
	strcpy(temp, input());
	s->age = strtod(temp, NULL);
	putchar('\n');
}

// Output the list
int output(struct family *s)
{
	int count = 0;

	// Check for empty list
	if (s == NULL)
	{
		puts("List is empty");
	}
	// Output all records
	else
	{
		while (s != NULL)
		{
			printf("%d: %s, your %s, is %d years old\n",
				   count + 1,
				   s->name,
				   s->relationship,
				   s->age);
			s = s->next;
			count++;
		}
	}
	putchar('\n');

	return (count);
}

// Save the linked list
void save(struct family *s)
{
	FILE *fp;
	int records, x;

	// Confirm that the list isn't empty
	if (s == NULL)
	{
		puts("List is empty\n");
		return;
	}

	// Count the number of records
	records = output(s);
	printf("%d records to save...", records);

	// Open the file
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to create %s\n\n", filename);
		/* don't quit on this error */
		return;
	}

	/* save all the records */
	for (x = 0; x < records; x++)
	{
		fwrite(s, sizeof(struct family), 1, fp);
		/* okay to change s here */
		s = s->next;
	}
	printf("%d written...", records);

	/* close the file */
	fclose(fp);

	puts("done!\n");
}

// Read the linked list from a file
void open(struct family *s)
{
	FILE *fp;
	int records;

	// Open a file
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Unable to read from %s\n\n", filename);
		// Don't quit on this error
		return;
	}
	printf("Opening file %s...", filename);

	// Retrieve the records
	records = 1;

	// Allocate the first structure
	while (1)
	{
		fread(s, sizeof(struct family), 1, fp);

		// The NULL pointer is saved
		if (s->next == NULL)
			break;
		s->next = allocate();
		s = s->next;
		records++;
	}
	printf("%d records read...", records);

	// Close the file
	fclose(fp);

	puts("done!\n");
}

int main()
{
	struct family *first, *current, *temp;
	int done, r, record;
	char command[SIZE];

	/* initialize first record to NULL */
	first = NULL;

	/* main menu and input loop */
	done = FALSE;
	puts("Family Database");
	while (!done)
	{
		/* initialize the current pointer to
		   the start of the list */
		current = first;
		/* output menu */
		puts("Menu:");
		puts("A - Add record");
		puts("D - Delete record");
		puts("L - List all records");
		puts("O - Open");
		puts("S - Save");
		puts("Q - Quit");
		printf("Choice: ");
		/* read input */
		strcpy(command, input());

		// Process selection
		switch (command[0])
		{
		// Add a record
		case 'A':
		case 'a':
			// Check to see if first record initialized
			if (first == NULL)
			{
				current = allocate();
				first = current;
				fill(current);
			}
			else
			{
				while (current->next)
					current = current->next;
				current->next = allocate();
				current = current->next;
				fill(current);
			}
			current->next = NULL;
			break;
		/* delete a record */
		case 'D':
		case 'd':
			if (first == NULL)
			{
				puts("Nothing to delete\n");
				break;
			}
			else
			{
				/* output the list */
				r = output(first);

				/* prompt */
				printf("Remove record 1 to %d? ", r);
				record = strtod(input(), NULL);
				if (record < 1 || record > r)
				{
					puts("Value out of range\n");
					break;
				}
				printf("Removing record %d...", record);
				/* test for first record */
				if (record == 1)
				{
					// Check to see if first is the only record
					if (first->next == NULL)
					{
						free(first);
						first = NULL;
					}
					else
					{
						temp = first;
						first = first->next;
						free(temp);
					}
					puts("Done!\n");
					break;
				}
				/* record to delete isn't the first record */
				/* visit the previous record */
				while (record - 2)
				{
					current = current->next;
					record--;
				}
				/* save the next record */
				temp = current->next;
				/* reset the current record pointer */
				current->next = temp->next;
				/* free the removed structure */
				free(temp);
				puts("Deleted\n");
			}
			break;
		/* list all records */
		case 'L':
		case 'l':
			output(first);
			break;
		/* open/retrieve existing records */
		case 'O':
		case 'o':
			first = allocate();
			open(first);
			break;
		/* save all records */
		case 'S':
		case 's':
			save(first);
			break;
		/* quit the program */
		case 'Q':
		case 'q':
			done = TRUE;
			puts("Bye!");
			break;
		/* something weird typed */
		default:
			puts("Unrecognized command");
		}
	}

	return (0);
}
