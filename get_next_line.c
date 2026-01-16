/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:00:34 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/14 13:00:46 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			bytes;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = "";
	bytes = 1;
	while (bytes > 0 && !ft_strrchr(line, '\n'))
	{
		if (buffer[0] == 0)
			bytes = read(fd, buffer, BUFFER_SIZE);
		i = ft_indexof(buffer);
		if (buffer[i] == '\0')
			bytes = read(fd, buffer + i, BUFFER_SIZE - i);
		i = ft_indexof(buffer);
		line = ft_strbufjoin(line, buffer, i);
		ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i - 1);
		ft_bzero(buffer + BUFFER_SIZE - i - 1, i + 1);
	}
	if (!line[0])
		return (NULL);
	return (line);
}
