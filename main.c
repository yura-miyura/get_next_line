/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:11:36 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/12/14 08:36:35by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>


int	main(int ac, char **av)
{
	char	*line1;
	char	*line2;
	char	*line3;
	int		fd1;
	int		fd2;
	int		fd3;

	if (ac == 4)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		while (1 == 1)
		{
			line1 = get_next_line(fd1);
			line2 = get_next_line(fd2);
			line3 = get_next_line(fd3);
			if (line1)
				printf("%s", line1);
			if (line2)
				printf("%s", line2);
			if (line3)
				printf("%s", line3);
			if (line1 == NULL && line2 == NULL && line3 == NULL)
				break;
		}
		close(fd1);
		close(fd2);
		close(fd3);
	}
}
