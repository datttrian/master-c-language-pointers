#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person
	{
		char name[32];
		int age;
	} president = {
		"George Washington",
		59};
	struct person *first;

	// Output regular structure
	printf("%s is %d years old\n",
		   president.name,
		   president.age);

	// Assign structure pointer
	first = &president;

	// Output pointer reference
	printf("%s is %d years old\n",
		   first->name,
		   first->age);

	return (0);
}
