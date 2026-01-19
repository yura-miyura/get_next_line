/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-18 10:07:51 by yartym            #+#    #+#             */
/*   Updated: 2026-01-18 10:07:51 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_indexof_nl(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE - 1 && buffer[i] && buffer[i] != '\n')
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size;
	int		s1_len;
	int		s2_len;

	if (!s1 && !*s2)
		return (NULL);
	if (!s1)
		s1 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len;
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	while (size-- > 0)
	{
		if (s2_len-- > 0)
			new_str[size] = s2[s2_len];
		else if (s1_len-- > 0)
			new_str[size] = s1[s1_len];
	}
	return (new_str);
}
