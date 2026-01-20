/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-18 10:08:18 by yartym            #+#    #+#             */
/*   Updated: 2026-01-18 10:08:18 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	size = s_len - start;
	if (start > s_len)
		size = 0;
	else if (size > len)
		size = len;
	substr = malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	char			*loc;
	unsigned char	cc;

	if (!s)
		return (NULL);
	loc = (char *) s;
	cc = c;
	while (*loc)
	{
		if (*loc == cc)
			return (loc);
		loc++;
	}
	if (*loc == cc)
		return (loc);
	return (NULL);
}

char	*ft_new_line(char *line, char *buffer)
{
	int		i;
	char	*tmp;
	char	*sub_line;

	i = ft_indexof_nl(buffer);
	tmp = line;
	sub_line = ft_substr(buffer, 0, i + 1);
	line = ft_strjoin(tmp, sub_line);
	free(sub_line);
	free(tmp);
	ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i);
	ft_bzero(buffer + BUFFER_SIZE - i - 1, i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			bytes;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	line = NULL;
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		if (!buffer[0])
			bytes = read(fd, buffer, BUFFER_SIZE);
		line = ft_new_line(line, buffer);
	}
	return (line);
}
