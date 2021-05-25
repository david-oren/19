#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{

	printf("/********************     %%p     *******************/\n\n");


	int array_size = 5;
	int i = 0;
	unsigned int nb[] = {0, 6, 451, 2000000, UINT_MAX};

	while (i < array_size)
	{
		printf("-------------------- start while loop with nb[%u] --------------------\n\n", nb[i]);

		printf ("%d\n\n",  printf("1 [%p]",  &nb[i]));

		printf ("%d\n\n",  printf("2 [NULL is undef] [%p]",  NULL));

		printf ("%d\n\n",  printf("1.1 [%5p]",  &nb[i]));


		printf ("%d\n\n",  printf("3 ! [%.p]",  &nb[i]));


		printf ("%d\n\n",  printf("3.4 ![%10.p]",  &nb[i]));


		printf ("%d\n\n",  printf("5 [%-5p]",  &nb[i]));

		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			printf ("\n**********  [  * loop with %d ]  *********\n\n", nb_2[i_2]);

			printf ("%d\n\n",    printf("10 [%*p]", nb_2[i_2], &nb[i]));


			i_2++;
		}
		i++;

	}

}
