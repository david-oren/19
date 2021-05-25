#include "limits.h"
#include "stdio.h"

int main ()
{



	char	c = 'a';
//	int		ii = 8;
	int		j = -12;
//	int		k = 123456789;
//	int		l = 0;
	int		m = -9999999;
	char	*n = "abcdefghijklmnop";

printf("%s", n);

	printf(" --- Return : %d\n", printf("Simple input test"));
	//printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", ii, j, k, l, m, n, c, c, j, j, j));
                                        printf(" --- Return : %d\n", printf("%d, %s, %c, %d, %u, %x, %X", m, n, c, c, j, j, j));

		printf ("%d\n\n",  printf("[%5x]", 5));

		printf ("%d\n\n",  printf("[%x]", j));
		printf ("%d\n\n",  printf("[%X]", j));



	/********************     %d     *******************/

	
	int size = 10;
	int i = 0;
	//int nb[] = {12, -12};
	int nb[] = {INT_MIN, 1000000, -451, -5, 0, -0, 6, 451, 2000000, INT_MAX};

	while (i < size)
	{

		printf ("%d\n\n",  printf("1 [%d]",  nb[i]));


		printf ("%d\n\n",  printf("[%5d]",  nb[i]));
		
		printf ("%d\n\n",  printf("[%05d]",  nb[i]));

		printf ("%d\n\n",  printf("[%.d]",  nb[i]));

		printf ("%d\n\n",  printf("[%10.d]",  nb[i]));
		
		printf ("%d\n\n",  printf("[%.10d]",  nb[i]));
		
		printf ("%d\n\n",   printf("5 [%10.6d]",  nb[i]));

		printf ("%d\n\n",  printf("[%0d]",  nb[i]));

		//here printf print nothing for thr %d
		printf ("%d\n\n",  printf("[%.0d]",  nb[i]));


		printf ("%d\n\n",  printf("10 [%5d]",  nb[i]));

		printf ("%d\n\n",  printf("[%d]",  nb[i]));

		printf ("%d\n\n",  printf("[%5.0d]",  nb[i]));

		//error
		printf ("%d\n\n",  printf("[%5.0d]", nb[i]));

		//error
		printf ("%d\n\n",  printf("[%0.5d]",  nb[i]));

		printf ("%d    |    the 0 flag is ignore because of the precision \n", printf("[%010.5d]", nb[i]));

		printf ("%d\n\n",    printf("[%010.*d]", -5, nb[i]));
		
		printf ("%d\n\n",  printf("15 [%0.5d]",  nb[i]));

		printf ("%d\n\n",  printf("[%10.5d]",  nb[i]));

		printf ("%d\n\n",  printf("[%11.10d]",  nb[i]));

		printf ("%d\n\n",  printf("[%5.d]",  nb[i]));

		printf ("%d\n\n",  printf("[%05d]",  nb[i]));

		printf ("%d\n\n",  printf("[%.5d]",  nb[i]));


		printf ("%d\n\n",  printf("[%.5d]",  nb[i]));

		printf ("%d\n\n",  printf("[%05d]",  nb[i]));


		printf ("%d\n\n",  printf("[%-.5d]",  nb[i]));


		//	*

		printf ("\n**********  [*]  *********\n\n");

//		int t[] = {}; idealement 2 int array pour chaque * mais flemme

	int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
	int size_2 = 7;
	int i_2 = 0;
	
	while (i_2 < size_2)	
	{	
		printf ("%d\n\n",  printf("446 (%d) [%*d]", nb_2[i_2], nb_2[i_2], nb[i]));

		printf ("%d\n\n",  printf("447[%5.*d]", nb_2[i_2],  nb[i]));

		printf ("%d\n\n",  printf("448[%5.*d]", nb_2[i_2],  nb[i]));

		printf ("%d\n\n",  printf("449[%5.*d]", nb_2[i_2],  nb[i]));

		printf ("%d\n\n",  printf("450[%*.d]", nb_2[i_2],  nb[i]));

		printf ("%d\n\n",  printf("441[%5.*d]", nb_2[i_2],  nb[i]));
//printf error		
//		printf ("%d\n\n",  printf("452[%*.*d]",  nb_2[i], nb_2[i], nb[i]));

//		printf ("%d\n\n",  printf("453[%0*.*d]",   nb_2[i], nb_2[i], nb[i]));

		i_2++;
	}
	i++;
}

		printf ("%d\n\n",  printf("452bb[%0*d]",    -10, 7));
		printf ("%d\n\n",  printf("453b[%0*.*d]",   5, 10, 7));
		printf ("%d\n\n",  printf("453c[%0*.*d]",   -5, -10, -7));
		printf ("%d\n\n",  printf("453d[%0*.*d]",   -5, 10, -7));
		printf ("%d\n\n",  printf("453e[%0*.*d]",   5, -10, -7));
		printf ("%d\n\n",  printf("452b[%*.*d]",  -5, -10, -7));
		printf ("%d\n\n",  printf("452c[%*.*d]",  5, 10, 7));
		printf ("%d\n\n",  printf("454[%-*.*d]",  5, 10, 7));

		// ça a prit 4 minutes.......................
		//printf ("%d\n\n",  printf("452 [%*d]", 100000000,  9 ));
		

		printf("%d\n\n",  printf("455 [%*d]", -1000,  9));






	/********************     string     *******************/
	//start %s


/*	printf (" ret: %d\n",  ft_printf("%5s",  "abc"));
	printf (" ret: %d\n",  printf("%5s",  "abc"));

	printf ("%d\n",  ft_printf("salut"));
	printf ("%d\n",  printf("salut"));


	//printf ("%d\n",  ft_printf("%05s",  "abc")); //undef
	//printf ("%d\n",  printf("%05s",  "abc"));

	printf ("%d\n", ft_printf("%5.sdef",  "hij"));
	printf ("%d\n",  printf("%5.sdef",  "hij"));


	printf ("%d\n", ft_printf("%.5s",   "klm"));
	printf ("%d\n",  printf("%.5s",   "klm"));

	printf ("%d\n", ft_printf("%*sdef", 5,  "mno"));
	printf ("%d\n", ft_printf("%*sdef",  5,  "mno"));

	printf ("%d\n",  ft_printf("%*.s",  5, "pqr"));
	printf ("%d\n",  printf("%*.s", 5 , "pqr"));

	printf ("%d\n",  printf("%*.*s", 5 , 2, "stu"));
	printf ("%d\n",  printf("%*.*s", 5 , 2 , "stu"));



	printf ("%d\n",  ft_printf("%.*s" , -5,  "vwx"));
	printf ("%d\n\n",  printf("%.*s", -5  , "vwx"));

	printf ("%d\n",  ft_printf("%.s" , "yza"));
	printf ("%d\n\n",  printf("%.s" , "yza"));



	printf ("%d\n",  ft_printf("[%5.0s]",  "abc"));
	printf ("%d\n\n",  printf("[%5.0s]",  "abc"));

	/ *  negligence flags * /

	printf ("%d\n",  ft_printf("[%5s.]",  "abc"));
	printf ("%d\n\n",  printf("[%5s.]",  "abc"));

	printf ("%d\n",  ft_printf("[%5s.*0]",  "abc"));
	printf ("%d\n\n",  printf("[%5s.*0]",  "abc"));

	printf ("%d\n",  ft_printf("[%5s-]",  "abc"));
	printf ("%d\n\n",  printf("[%5s-]",  "abc"));

	/ * negligence flags * /

	/ * undef * /

	//printf ("%d\n",  ft_printf("[%0.5s]",  "abc"));
	//printf ("%d\n\n",  printf("[%0.5s]",  "abc"));

	//printf ("%d\n",  ft_printf("[%5-",  "abc"));
	//printf ("%d\n\n",  printf("[%5-]",  "abc"));

	printf ("%d\n",  ft_printf("[%]",  "abc"));
	printf ("%d\n",  ft_printf("[%]",  "abc"));

	/ * undef * /
*/
	//end %s










	/********************     garbage     *******************/


	//start bordel

	//ft_printf("[%1s]def", "abc");

	//seulement si . est present


	//marche po, prends pas en compte la taille du nombre, affiche just x spaces
	//printf ("[%d]\n", printf("%2dabc", 12));
	//printf ("[%d]\n", ft_printf("%2dabc", 12));







	//ft_printf ( "[,  return: %d]", ft_printf("yo"));
	//	ft_printf ( "[,  return: %d]", ft_printf("%d", -6));
	//	ft_printf ( "[,  return: %d]", ft_printf("[%d], [%d], [%d]", 0, 1, -12 ));
	//	ft_printf ( "[,  return: %d]", ft_printf("[%u], [%u], [%u]", 0, 1, -12 ));


	/*i	char *s = "yo";
	  printf ("ft_printf: ");
	  printf ( "[,  return: %d]", ft_printf("[%p]", s  ));
	  printf ("\nprintf: ");
	  printf ( "[,  return: %d]", printf("[%p]", s  ));
	 */


	//	ft_printf("%yo\n", 5); //boucle infinie
	//	printf("%yo", 5); //warning compile pas sur mac de lecole, mais sinn affiche simplement %yo

	//	printf("%d"); //random nombres
	//	ft_printf("%d"); //random nombres

	//printf("%p", NULL); //return 5, print (nil)
	/*
	   printf ("[%d]\n", ft_printf("%2iabc", 5));

	   printf ("[%d]\n", printf("%2iabc", 5));


	   printf ("[%d]\n", printf("%0iabc", 5));
	   printf ("[%d]\n", ft_printf("%0iabc", 5));
	 */


}
