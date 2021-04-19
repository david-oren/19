#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{


printf("/********************     %%d     *******************/\n\n");


	int i = 0;
	int nb[] = {INT_MIN, 1000000, -451, -5, 0, -0, 6, 451, 2000000, INT_MAX};


		printf ("%d\n\n",  printf("1 [%p]",  &nb[i]));


		printf ("%d\n\n",  printf("[%25p]",  &nb[i]));


		printf ("%d\n\n",  printf("[%.p]",  &nb[i]));

		printf ("%d\n\n",  printf("[%30.p]",  &nb[i]));




		printf ("%d\n\n",  printf("[%-26p]",  &nb[i]));


}
