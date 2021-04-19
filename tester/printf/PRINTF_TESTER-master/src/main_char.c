#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{
	printf ("********************     %%c     *******************\n\n");


	int i = 67;
	while (i < 73)
	{

		printf ("%d\n\n",  printf("1 [%c]",  i));
		printf ("%d\n\n",  printf("2 [%1c]",  i));
		printf ("%d\n\n",  printf("3 [%15c]",  i));
		printf ("%d\n\n",  printf("4 [%-5c]", i));

		printf ("%d\n\n",  printf("5 [%.c]",  i));

		printf ("%d\n\n",  printf("6 [%10.c]",  i));

		printf ("%d\n\n",  printf("7 [%5.c]",  i));


	int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			printf ("%d\n\n",  printf("446 (%d) [%*c]", nb_2[i_2], nb_2[i_2], i));

			i_2++;
		}
		i++;
	}
}
