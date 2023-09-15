#include <stdio.h>

int main()
{
	char a = 'A';
	printf("Value of variable 'a': %c\n", a);
	printf("Address of variable 'a': %p\n", &a);
	printf("Size of variable 'a': %lu\n", sizeof(a));

	return (0);
}
