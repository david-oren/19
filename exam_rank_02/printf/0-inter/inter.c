#include <unistd.h>

void	inter(char *str1, char *str2)
{
	int		i;
	char	tab[256];
	
	i = 0;
	while (i < 256)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (tab[(int)str2[i]] == 0)
			tab[(int)str2[i]] = 1;
		i++;
	}
	i = 0;
	while (str1[i])
	{
		if (tab[(int)str1[i]] == 1)
		{
			write(1, &str1[i], 1);
			tab[(int)str1[i]] = 0;
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
