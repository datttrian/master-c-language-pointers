#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"};
	int x;

	for (x = 0; x < 4; x++)
		printf("Address: %p = %s\n", fruit[x], fruit[x]);

	return (0);
}
