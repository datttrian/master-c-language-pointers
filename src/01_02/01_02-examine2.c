#include <stdio.h>

int main()
{
	int a = 12345;

	printf("Value of variable 'a': %d\n", a);
	printf("Address of variable 'a': %p\n", &a);
	printf("Size of variable 'a': %lu\n", sizeof(a));

	return (0);
}
