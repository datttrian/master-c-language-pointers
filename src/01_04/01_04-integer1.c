#include <stdio.h>
#include <stdlib.h>

int *iptr(void)
{
	static int a = 53;
	return (&a);
}

int main()
{
	int *x;
	x = iptr();

	if (x == NULL)
	{
		fprintf(stderr, "Memory error\n");
		exit(1);
	}

	printf("The address returned is %p\n", x);
	printf("The value returned is %d\n", *x);

	return (0);
}
