#include <stdio.h>

int main()
{
	int a[5] = {11, 22, 33, 44, 55};

	for (int i = 0; i < 5; i++)
		printf("%p\n", &a[i]);

	return (0);
}
