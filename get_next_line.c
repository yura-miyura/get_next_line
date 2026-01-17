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
	substr = malloc(sizeof (char) * (size + 1));
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

char	*ft_strrchr(const char *s, int c)
{
	char			*loc;
	unsigned char	cc;
	size_t			i;

  if (!s)
    return (NULL);
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
  static char	buffer[BUFFER_SIZE + 1] = {0};
  char    *line;
  char    *tmp;
  char    *sub_line;
  int   i;
  int   bytes;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  bytes = 1;
  if (!buffer[0])
    bytes = read(fd, buffer, BUFFER_SIZE);
  line = NULL;
  while (bytes > 0 && !ft_strrchr(line, '\n'))
  {
    i = ft_indexof(buffer);
    if (!buffer[i])
      bytes = read(fd, buffer + i, BUFFER_SIZE - i);
    i = ft_indexof(buffer);
    tmp = line;
    sub_line = ft_substr(buffer, 0, i + 1);
    line = ft_strjoin(tmp, sub_line);
    free(sub_line);
    free(tmp);
    ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i);
    ft_bzero(buffer + BUFFER_SIZE -  i - 1,  i + 1);
  }
  return (line);
}
