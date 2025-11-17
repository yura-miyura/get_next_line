/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:11:36 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/17 12:07:18 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (1 == 1)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			printf("%s", line);
		}
		close(fd);
		printf("%d\n", ARG_MAX);
	}
}
