# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalecki <amalecki@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 12:39:01 by amalecki          #+#    #+#              #
#    Updated: 2021/11/29 15:02:42 by amalecki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c print_char.c print_integer.c print_string.c \
print_unsigned.c print_xdecimal.c

BONUS_SOURCE = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils_2_bonus.c \
print_char_bonus.c print_integer_bonus.c print_string_bonus.c print_unsigned_bonus.c \
print_xdecimal_bonus.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

RM = rm -rf

OBJECTS 	= ${SOURCE:.c=.o}
BONUS_OBJECTS 	= ${BONUS_SOURCE:.c=.o}

OBJECTS_DIR 	= OBJECTS/
OBJECTS_IN_DIR 	= ${addprefix ${OBJECTS_DIR}, ${OBJECTS}}
BONUS_OBJECTS_IN_DIR 	= ${addprefix ${OBJECTS_DIR}, ${BONUS_OBJECTS}}

NAME 	= libftprintf.a

${NAME}:	${OBJECTS_IN_DIR}
	ar -rcsv ${NAME} ${OBJECTS_IN_DIR}

all:	${NAME}

bonus: 		${BONUS_OBJECTS_IN_DIR}
	ar -rcsv ${NAME} ${BONUS_OBJECTS_IN_DIR}

$(OBJECTS_DIR)%.o : %.c
	mkdir -p ${OBJECTS_DIR}
	${CC} ${CFLAGS} $< -o $@

clean: 
	${RM} ${OBJECTS_DIR}

fclean: 	clean
	${RM} ${NAME}

re: 	fclean all

.PHONY: 	all clean fclean re
