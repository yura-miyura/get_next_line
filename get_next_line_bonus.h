/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:09:34 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/17 20:17:48 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

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
