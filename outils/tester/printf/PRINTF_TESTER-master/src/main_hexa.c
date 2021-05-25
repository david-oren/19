#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{

	printf("-------------------- start[%%x]] --------------------\n\n");

	int array_size = 5;
	int i = 0;
	unsigned int nb[] = {0, 6, 451, 2000000, UINT_MAX};

	while (i < array_size)
	{
	printf("-------------------- start while loop with nb[%u] --------------------\n\n", nb[i]);
		printf ("%d\n\n",  printf("1 [%x]",  nb[i]));

		printf ("%d\n\n",  printf("1.1 [%5x]",  nb[i]));

		printf ("%d\n\n",  printf("2 [%05x]",  nb[i]));

		printf ("%d\n\n",  printf("2.2 [%0x]",  nb[i]));

		printf ("%d\n\n",  printf("3 ! [%.x]",  nb[i]));

		printf ("%d\n\n",  printf("3.1 ! [%.0x]",  nb[i]));
	
		printf ("%d\n\n",  printf("3.2 ! [%.5x]",  nb[i]));
		
		printf ("%d\n\n",  printf("3.3 ! [%0.5x]",  nb[i]));

		printf ("%d\n\n",  printf("3.4 ![%10.x]",  nb[i]));

		printf ("%d\n\n",  printf("3.5 ! [%5.0x]",  nb[i]));
	
		printf ("%d\n\n",  printf("3.6 ! [%.10x]",  nb[i]));

		printf ("%d\n\n",  printf("3.7 ! [%10.6x]",  nb[i]));

		printf ("%d\n\n",  printf("4 [%010.5x]", nb[i]));

		printf ("%d\n\n",  printf("5 [%-5x]",  nb[i]));

		printf ("%d\n\n",  printf("5.1 ![%-.5x]",  nb[i]));


		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
		printf ("\n**********  [  * loop with %d ]  *********\n\n", nb_2[i_2]);

			printf ("%d\n\n",    printf("10 [%*x]", nb_2[i_2], nb[i]));

			printf ("%d\n\n",  printf("[%*.x]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("[%*.0x]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("[%*.*x]", nb_2[i_2], nb_2[i], nb[i]));

			printf ("%d\n\n",  printf("453[%0*.*x]",   nb_2[i], nb_2[i], nb[i]));

			printf ("%d\n\n",    printf("10 [%010.*x]", nb_2[i_2], nb[i]));

			printf ("%d\n\n",  printf("441[%5.*x]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("452bb[%0*x]", nb_2[i_2], 7));

			printf ("%d\n\n",  printf("453b !! [%0*.*x]",   nb_2[i_2], nb_2[i_2], 7));
			i_2++;
		}
		i++;

	}

	printf ("%d\n\n",  printf("453b !![%0*.*x]",   5, 10, 7));
	printf ("%d\n\n",  printf("453c[%0*.*x]",   -5, -10, -7));
	printf ("%d\n\n",  printf("453d[%0*.*x]",   -5, 10, -7));
	printf ("%d\n\n",  printf("453e[%0*.*x]",   5, -10, -7));
	printf ("%d\n\n",  printf("453f[%*.*x]",  -5, -10, -7));
	printf ("%d\n\n",  printf("453g[%*.*x]",  5, 10, 7));
	printf ("%d\n\n",  printf("453h[%-*.*x]",  5, 10, 7));



	printf ("%d\n\n",  printf("55 [%-5X]",  5));
	printf ("%d\n\n",  printf("56 [%-5i]",  5));

}
