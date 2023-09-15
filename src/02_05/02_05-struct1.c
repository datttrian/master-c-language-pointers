#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct Person
	{
		char *name;
		int *age;
	} my;
	char n[] = "Jennifer";

	// Allocate storage for the age integer
	my.age = (int *)malloc(sizeof(int) * 1);
	if (my.age == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}

	// Assign value; the asterisk is required, but the standard dot operator is used
	*my.age = 26;

	// Because 'n' is an array and 'my.name' is a pointer, you can just copy the base address again, the dot operator is used
	my.name = n;

	// Output results  the asterisk
	printf("%s is %d years old\n",
		   my.name,	 //'my.name' is a character pointer and the asterisk isn't required
		   *my.age); // the asterisk is required for 'my.age'

	return (0);
}
