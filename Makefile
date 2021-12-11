# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:17:23 by amalecki          #+#    #+#              #
#    Updated: 2021/12/11 08:04:19 by amalecki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SOURCE = server.c

CLIENT_SOURCE = client.c

CLIENT = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME    = server

${NAME}:        ${SERVER_SOURCE} ${CLIENT} server.h
		${CC} ${CFLAGS} ${SERVER_SOURCE} -o $@

${CLIENT}:        ${CLIENT_SOURCE} client.h
		${CC} ${CFLAGS} ${CLIENT_SOURCE} -o $@

all:    ${NAME}

clean:
		${RM} ${NAME} ${CLIENT}

fclean:         clean
		${RM} ${NAME} ${CLIENT}

re:     fclean all

.PHONY:         all clean fclean re