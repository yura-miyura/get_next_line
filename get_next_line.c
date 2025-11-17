/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:03:21 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/14 13:32:18 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_buffer(int fd, char buffer[BUFFER_SIZE], char *line)
{
	int		i;
	char	*new_line;
	size_t	bytes;
	ssize_t	new_content;

	i = ft_indexof(buffer);
	new_line = ft_strbufjoin(line, buffer, i);
	bytes = BUFFER_SIZE - i - 1;
	ft_memmove(buffer, buffer + i + 1, bytes);
	ft_bzero(buffer + bytes, i + 1);
	new_content = read(fd, buffer + bytes, i + 1);
	if (!new_content && !new_line[0])
		return (NULL);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	size_t		line_len;

	if (fd < 0)
		return (NULL);
	if (buffer[0] == 0)
		read(fd, buffer, BUFFER_SIZE);
	line = "";
	line_len = 1;
	while (line[line_len - 1] != '\n')
	{
		line = update_buffer(fd, buffer, line);
		if (!line)
			break ;
		line_len = ft_strlen(line);
	}
	return (line);
}
