/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bounus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:09:34 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/17 12:03:56 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_memmove(void *dst, const void *src, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_indexof(char *str);
char	*ft_strbufjoin(char const *s, char BUFFER[BUFFER_SIZE], int i);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
