#include <stdio.h>

int main()
{
	int a = 12345;
	int *ptr;
	ptr = &a;
	// int *ptr = &a;

	printf("Value of variable 'a': %d\n", *ptr);
	printf("Address of variable 'a': %p\n", ptr);

	return (0);
}
