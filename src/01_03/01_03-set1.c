#include <stdio.h>

void set(int *x, int *y)
{
	*x = 100;
	*y = 200;
}

int main()
{
	int a, b;

	set(&a, &b);
	printf("A = %d and B = %d\n", a, b);

	return (0);
}
