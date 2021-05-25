#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{
	printf("/********************     %%     *******************/\n\n");


	int i = 67;
	while (i < 73)
	{

		printf ("%d\n\n",  printf("1 [%%]"));
		printf ("%d\n\n",  printf("2 [%1%]"));
		printf ("%d\n\n",  printf("3 [%15%]"));
		printf ("%d\n\n",  printf("4 [%15%]"));
		printf ("%d\n\n",  printf("5[%0%]"));
		printf ("%d\n\n",  printf("6[%05%]"));

		printf ("%d\n\n",  printf("7[%.%]"));

		printf ("%d\n\n",  printf("8[%10.%]"));
		printf ("%d\n\n",  printf("9[%.10%]"));
		printf ("%d\n\n",  printf("10[%.1%]"));
		printf ("%d\n\n",  printf("11[%10.1%]"));
		printf ("%d\n\n",  printf("12[%10.5%]"));

		printf ("%d\n\n",  printf("[%5.%]"));
		printf ("%d\n\n",  printf("[%0.5%]"));
		printf ("%d\n\n",  printf("[%.5%]"));


	int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			printf ("%d\n\n",  printf("446 (%d) [%*%]", nb_2[i_2], nb_2[i_2]));

			i_2++;
		}
		i++;
	}

       printf ("%d\n\n",  printf("452bb[%0*%]",    -10));

	//could be undefined behavior for %% but man not clear
      //  printf ("%d\n\n",  printf("453b[%0*.*%]",   5, 10));
  
        printf ("%d\n\n",  printf("453c[%0*.*%]",   -5, -10));
        printf ("%d\n\n",  printf("453d[%0*.*%]",   -5, 10));
        printf ("%d\n\n",  printf("453e[%0*.*%]",   5, -10));
        printf ("%d\n\n",  printf("452b[%*.*%]",  -5, -10));
        printf ("%d\n\n",  printf("452c[%*.*%]",  5, 10));
        printf ("%d\n\n",  printf("454[%-*.*%]",  5, 10));
    


}
