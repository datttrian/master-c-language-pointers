#include <stdio.h>

int main()
{
	char a;
	char *ptr;

	// Initialize variables
	a = 'A';
	printf("Value of variable 'a': %c\n", a);

	// Assign ptr to a's address
	ptr = &a;
	printf("Address of variable 'a': %p\n", ptr);
	printf("Value of pointer 'ptr': %c\n", *ptr);

	return (0);
}
