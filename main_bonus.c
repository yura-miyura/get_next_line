#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char    *line;
	int     fd;
	char    *line2;
	int     fd2;

	if (ac == 3)
	{
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);

		line = get_next_line(fd);
		line2 = get_next_line(fd2);

		printf("FD 1: %s", line);
		printf("FD 2: %s", line2);
		// while (line || line2)
		// {
		// 	if (line)
		// 	{
		// 		printf("FD 1: %s", line);
		// 		free(line);
		// 		line = get_next_line(fd);
		// 	}
		// 	if (line2)
		// 	{
		// 		printf("FD 2: %s", line2);
		// 		free(line2);
		// 		line2 = get_next_line(fd2);
		// 	}
		// }
		free(line);
		free(line2);
		close(fd);
		close(fd2);
	}
}

