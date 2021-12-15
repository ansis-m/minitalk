# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 12:39:01 by amalecki          #+#    #+#              #
#    Updated: 2021/12/15 17:27:35 by amalecki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c print_char.c print_integer.c print_string.c \
print_unsigned.c print_xdecimal.c ft_atoi.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

RM = rm -rf

OBJECTS 	= ${SOURCE:.c=.o}

OBJECTS_DIR 	= OBJECTS/
OBJECTS_IN_DIR 	= ${addprefix ${OBJECTS_DIR}, ${OBJECTS}}

NAME 	= libftprintf.a

${NAME}:	${OBJECTS_IN_DIR}
	ar -rcsv ${NAME} ${OBJECTS_IN_DIR}

all:	${NAME}

$(OBJECTS_DIR)%.o : %.c
	mkdir -p ${OBJECTS_DIR}
	${CC} ${CFLAGS} $< -o $@

clean: 
	${RM} ${OBJECTS_DIR}

fclean: 	clean
	${RM} ${NAME}

re: 	fclean all

.PHONY: 	all clean fclean re
