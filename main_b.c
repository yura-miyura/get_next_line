#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	char	*line2;
	int		fd2;

	if (ac == 3)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		fd2 = open(av[2], O_RDONLY);
		line2 = get_next_line(fd2);
		while (line || line2)
		{
			if (line)
			{
				printf("%s", line);
				free(line);
				line = get_next_line(fd);
			}
			if (line2)
			{
				printf("%s", line2);
				free(line2);
				line2 = get_next_line(fd2);
			}
		}
		free(line);
		close(fd);
		free(line2);
		close(fd2);
	}
}

