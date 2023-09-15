#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10];

	// Fill storage
	for (int i = 0; i < 10; i++)
	{
		a[i] = i * 100;
		/* a[x] ~ *(p+x) */
	}

	/* output the buffer's contents */
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
		/* a[x] ~ *(p+x) */
	}

	return (0);
}
