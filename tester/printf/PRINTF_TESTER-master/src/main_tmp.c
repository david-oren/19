#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

int main ()
{

//	ft_printf ("%d\n\n",  ft_printf("[%5x]", 5));



	/********************     %d     *******************/


	int size = 3;
	int i = 0;

	char **nb  = malloc(5 * sizeof(char*));

	//NULL est undef	

	nb[0] = "aloa";
	nb[1] = strdup("okkkkkkkkkkkkkkkkk");
	nb[2] = strdup("");;
	nb[3] = NULL;
	nb[4] = 0;

	while (i < size)
	{

		ft_printf("-------------------- start while with %s --------------------", nb[i]);

		ft_printf ("%d\n\n",  ft_printf("1 [%s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[ 2 [%s] okkk ]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%5s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%.s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%10.s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%.10s]",  nb[i]));

		ft_printf ("%d\n\n",   ft_printf("5 [%10.6s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("10 [%sd]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%5.0s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%5.0s]", nb[i]));

		//ft_printf ("%d\n\n",  ft_printf("15 [%0.5s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%10.5s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%11.10s]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%5.s]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%.5s]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%.5s]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%-.5s]",  nb[i]));



		ft_printf ("\n**********  [*]  *********\n\n");


		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			ft_printf ("%d\n\n",  ft_printf("446 (%d) [%*s]", nb_2[i_2], nb_2[i_2], nb[i]));

			ft_printf ("%d\n\n",  ft_printf("447[%5.*s]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("448[%5.*s]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("449[%5.*s]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("450[%*.s]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("441[%5.*s]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("452[%*.*s]",  nb_2[i], nb_2[i], nb[i]));

			i_2++;
		}


		i++;
	}

	ft_printf ("%d\n\n",  ft_printf("452b[%*.*s]",  -5, -10, "sd"));
	ft_printf ("%d\n\n",  ft_printf("452c[%*.*s]",  5, 10, "sd"));
	ft_printf ("%d\n\n",  ft_printf("454[%-*.*s]",  5, 10, "sd"));

	// ça a prit 4 minutes.......................
	//		ft_printf ("%d\n\n",  ft_printf("452 [%*s]", 100000000,  "abc"));	

	ft_printf("%d\n\n",  ft_printf("455 [%*s]", -1000,  "cba"));









	ft_printf ("%d\n",  ft_printf("%5.sdef",  "hij"));


	ft_printf ("%d\n",  ft_printf("%.5s",   "klm"));

	ft_printf ("%d\n",  ft_printf("%*.s", 5 , "pqr"));

	ft_printf ("%d\n",  ft_printf("%*.*s", 5 , 2, "stu"));
	ft_printf ("%d\n",  ft_printf("%*.*s", 5 , 2 , "stu"));



	ft_printf ("%d\n\n",  ft_printf("%.*s", -5  , "vwx"));

	ft_printf ("%d\n\n",  ft_printf("%.s" , "yza"));


	//care flags after type field

	ft_printf ("%d\n\n",  ft_printf("[%5.0s]",  "abc"));


	ft_printf ("%d\n\n",  ft_printf("[%5s.]",  "abc"));

	ft_printf ("%d\n\n",  ft_printf("[%5s.*0]",  "abc"));

	ft_printf ("%d\n\n",  ft_printf("[%5s-]",  "abc"));




	//end %s









	return (0);
}
