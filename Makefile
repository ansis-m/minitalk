# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:17:23 by amalecki          #+#    #+#              #
#    Updated: 2021/12/12 08:49:26 by amalecki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SOURCE = server.c server_utils.c
CLIENT_SOURCE = client.c client_utils.c
DIR = ./my_ft_printf
PRINTF = ${DIR}/libftprintf.a

CLIENT = client
SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra #-Werror                TO BE REMOVED
RM = rm -rf

all:    ${CLIENT} ${SERVER}

${SERVER}:        ${SERVER_SOURCE} ${PRINTF} server.h
		${CC} ${CFLAGS} ${SERVER_SOURCE} ${PRINTF} -o $@

${CLIENT}:        ${CLIENT_SOURCE} ${PRINTF} client.h
		${CC} ${CFLAGS} ${CLIENT_SOURCE} ${PRINTF} -o $@

${PRINTF}: 
		$(MAKE) -C ${DIR}

clean:
		${RM} ${DIR}/OBJECTS

fclean:         clean
		${RM} ${SERVER} ${CLIENT}
		${RM} ${PRINTF}

re:     fclean all

.PHONY:         all clean fclean re
