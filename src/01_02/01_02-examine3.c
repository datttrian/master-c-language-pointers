#include <stdio.h>

int main()
{
	double a = 6.0221409e23;

	printf("Value of variable 'a': %e\n", a);
	printf("Address of variable 'a': %p\n", &a);
	printf("Size of variable 'a': %lu\n", sizeof(a));

	return (0);
}
