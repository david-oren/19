#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

int main ()
{


	printf("********************     start %%s tests     *******************\n\n");

	int size = 3;
	int i = 0;

	char **nb  = malloc(5 * sizeof(char*));

	//NULL est undef, pas teste ici

	nb[0] = "aloa";
	nb[1] = strdup("okkkkkkkkkkkkkkkkk");
	nb[2] = strdup("");;
	nb[3] = NULL;
	nb[4] = 0;

	while (i < size)
	{

		printf("-------------------- start while loop with var: [%s] --------------------\n\n", nb[i]);

		printf ("%d\n\n",  printf("1 [%s]",  nb[i]));

		printf ("%d\n\n",  printf("2 ( [%s] okkk )",  nb[i]));

		printf ("%d\n\n",  printf("3 [%5s]",  nb[i]));

		printf ("%d\n\n",  printf("4 [%.s]",  nb[i]));

		printf ("%d\n\n",  printf("5 [%10.s]",  nb[i]));

		printf ("%d\n\n",  printf("6 [%.10s]",  nb[i]));

		printf ("%d\n\n",   printf("7 [%10.6s]",  nb[i]));

		printf ("%d\n\n",  printf("8 [%sd]",  nb[i]));

		printf ("%d\n\n",  printf("9 [%5.0s]",  nb[i]));

		printf ("%d\n\n",  printf("10 [%5.0s]", nb[i]));

		//no 0 flag with %s
//		printf ("%d\n\n",  printf("15 [%0.5s]",  nb[i]));
//		printf( "[%05.5s]", "dsf"); 

		printf ("%d\n\n",  printf("11 [%10.5s]",  nb[i]));

		printf ("%d\n\n",  printf("12 [%11.10s]",  nb[i]));

		printf ("%d\n\n",  printf("13 [%5.s]",  nb[i]));

		printf ("%d\n\n",  printf("14 [%.5s]",  nb[i]));


		printf ("%d\n\n",  printf("15 [%.5s]",  nb[i]));


		printf ("%d\n\n",  printf("16 [%-.5s]",  nb[i]));



		printf ("\n**********  [*]  *********\n\n");


		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			printf ("%d\n\n",  printf("20 (%d) [%*s]", nb_2[i_2], nb_2[i_2], nb[i]));

			printf ("%d\n\n",  printf("21[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("22[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("23[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("24[%*.s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("25[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("26[%*.*s]",  nb_2[i], nb_2[i], nb[i]));

			i_2++;
		}


		i++;
	}

	printf ("%d\n\n",  printf("452[%*.*s]",  -5, -10, "sd"));
	printf ("%d\n\n",  printf("453[%*.*s]",  5, 10, "sd"));
	printf ("%d\n\n",  printf("454[%-*.*s]",  5, 10, "sd"));

	// ça a prit 4 minutes.......................
	//		printf ("%d\n\n",  printf("452 [%*s]", 100000000,  "abc"));	

	printf("%d\n\n",  printf("455 [%*s]", -1000,  "cba"));






	printf ("%d\n",  printf("456 %5.sdef",  "hij"));


	printf ("%d\n",  printf("457 %.5s",   "klm"));

	printf ("%d\n",  printf("458 %*.s", 5 , "pqr"));

	printf ("%d\n",  printf("459 %*.*s", 5 , 2, "stu"));
	printf ("%d\n",  printf("460 %*.*s", 5 , 2 , "stu"));



	printf ("%d\n\n",  printf("461 %.*s", -5  , "vwx"));

	printf ("%d\n\n",  printf("462 %.s" , "yza"));


	//care flags after type field

	printf ("%d\n\n",  printf("463 [%5.0s]",  "abc"));

	printf ("%d\n\n",  printf("464 [%5s.]",  "abc"));

	printf ("%d\n\n",  printf("465 [%5s.*0]",  "abc"));

	printf ("%d\n\n",  printf("466 [%5s-]",  "abc"));


	return (0);
}
