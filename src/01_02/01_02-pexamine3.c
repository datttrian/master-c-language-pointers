#include <stdio.h>

int main()
{
	double a = 6.0221409e23;
	double *ptr;
	ptr = &a;
	// int *ptr = &a;

	printf("Value of variable 'a': %e\n", *ptr);
	printf("Address of variable 'a': %p\n", ptr);

	return (0);
}
