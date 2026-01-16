/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:03:21 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/14 12:58:42 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*loc;
	unsigned char	cc;
	size_t			i;

	loc = (char *) s;
	cc = c;
	i = ft_strlen(loc) + 1;
	while (i > 0)
		if (*(loc + --i) == cc)
			return (loc + i);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE];
	char		*line;
	int			bytes;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = "";
	bytes = 1;
	while (bytes > 0 && !ft_strrchr(line, '\n'))
	{
		if (buffer[fd][0] == 0)
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
		i = ft_indexof(buffer[fd]);
		if (buffer[fd][i] == '\0')
			bytes = read(fd, buffer[fd] + i, BUFFER_SIZE - i);
		i = ft_indexof(buffer[fd]);
		line = ft_strbufjoin(line, buffer[fd], i);
		ft_memmove(buffer[fd], buffer[fd] + i + 1, BUFFER_SIZE - i - 1);
		ft_bzero(buffer[fd] + BUFFER_SIZE - i - 1, i + 1);
	}
	if (!line[0])
		return (NULL);
	return (line);
}
