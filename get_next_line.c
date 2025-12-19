/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:03:21 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/12/14 20:29:52y yuriiartymi      ###   ########.fr       */
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


static char	*update_buffer(int fd, char buffer[BUFFER_SIZE], char *line)
{
	int		i;
	size_t	bytes;
	ssize_t	new_content;
	char	*new_line;

	if (!buffer[0])
		new_content = read(fd, buffer, BUFFER_SIZE);
	i = ft_indexof(buffer);
	new_line = ft_strbufjoin(line, buffer, i);
	bytes = BUFFER_SIZE - i - 1;
	ft_memmove(buffer, buffer + i + 1, bytes);
	ft_bzero(buffer + bytes, i + 1);
	new_content = read(fd, buffer + bytes, i + 1);
	if (new_content < 0 || !new_line[0])
		return (NULL);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = "";
	while (!ft_strrchr(line, '\n'))
	{
		line = update_buffer(fd, buffer, line);
		if (!line || !buffer[0])
			break ;
	}
	return (line);
}
