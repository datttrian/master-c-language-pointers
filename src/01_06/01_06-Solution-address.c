#include <stdio.h>

int main()
{
	char a, *x;
	int b, *y;

	printf("Address of 'a': %p\n", &a);
	printf("Address of 'b': %p\n", &b);

	x = &a;
	y = &b;
	printf("Address of 'a': %p\n", x);
	printf("Address of 'b': %p\n", y);

	return (0);
}
