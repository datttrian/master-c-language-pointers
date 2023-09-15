#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit;
	for(x=0; x<4; x++)
	{
		printf("Address: %p = %s\n", *f, *f );
		f++;
	}

	return(0);
}
