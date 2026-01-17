/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:10:54 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/17 12:02:55 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_src = src;
	tmp_dest = dest;
	if (tmp_dest <= tmp_src)
		while (n--)
			*tmp_dest++ = *tmp_src++;
	else
	{
		tmp_dest += n;
		tmp_src += n;
		while (n--)
			*--tmp_dest = *--tmp_src;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	char	*s_tmp;

	s_tmp = s;
	if (s)
		while (n--)
			s_tmp[n] = 0;
}

int	ft_indexof(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE - 1)
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strbufjoin(char const *s, char BUFFER[BUFFER_SIZE], int i)
{
	char	*new_str;
	size_t	size;
	int		s_len;

	if (!s || !BUFFER)
		return (NULL);
	s_len = ft_strlen(s);
	size = s_len + i + 1;
	new_str = malloc(sizeof (char) * size + 1);
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	while (size-- > 0)
	{
		if (i >= 0)
			new_str[size] = BUFFER[i--];
		else if (s_len-- > 0)
			new_str[size] = s[s_len];
	}
	return (new_str);
}
