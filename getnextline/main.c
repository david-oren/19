#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;
	int		fd2;

	i = 0;
	ret = 0;
	line = NULL;
	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	fd2 = open((argv[2]), O_RDONLY);
	
	get_next_line(fd, &line);
	printf("\n%s", line);
	free(line);
	get_next_line(fd2, &line);
	printf("\n%s", line);
	free(line);
	get_next_line(fd, &line);
	printf("\n%s", line);
	free(line);
	get_next_line(fd2, &line);
	printf("\n%s", line);
	free(line);
	get_next_line(fd, &line);
	printf("\n%s", line);
	free(line);
	get_next_line(fd2, &line);
	printf("\n%s", line);
	free(line);
	// while ((ret = get_next_line(fd, &line)) == 1)
	// {
	// 	printf("\n%s", line);
	// 	//printf("%d\n", ret);
	// 	i++;
	// 	free(line);
	// }
	printf("|%d|\n", ret);
	close(fd);
	return(0);
}
