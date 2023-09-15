#include <stdio.h>

int main()
{
	int a[5] = {11, 22, 33, 44, 55};
	int *p;

	p = a;
	for (int i = 0; i < 5; i++)
	{
		printf("%p\n", p);
		p++;
	}

	return (0);
}
