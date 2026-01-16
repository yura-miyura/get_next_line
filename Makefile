# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 13:06:38 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/01/14 13:06:39 by yuriiartymi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main
OFLAGS = -Wall -Wextra -Werror -g3
CC = cc
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c main.c
		
BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c 

m: ${SRCS}
	${CC} ${OFLAGS} $^ -o ${NAME} 

b: ${BONUS}
	${CC} ${OFLAGS} $^ -o ${NAME} 

clean:
	${RM} main