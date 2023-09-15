#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x,y;

	f = fruit;
	for(x=0; x<4; x++)
	{
		y = 0;
		while( *(*f+y) )
		{
			putchar( *(*f+y) );
			y++;
		}
		putchar('\n');
		f++;
	}

	return(0);
}
