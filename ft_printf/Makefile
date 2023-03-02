# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 12:55:59 by jsabound          #+#    #+#              #
#    Updated: 2023/02/20 14:40:37 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs/
SRCS = ft_strchr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putnbr_fd.c\
	   ft_arg.c\
	   ft_strlen.c\
	   ft_printf_utils.c\
	   ft_printf.c \

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
RM = rm -f
.c.o:	
	${CC} -Wall -Wextra -Werror -c $< -o ${<:.c=.o}
${NAME}: ${OBJS}	
	ar rc ${NAME} ${OBJS}
all : ${NAME}
clean :
	${RM} ${OBJS}
fclean : clean	
	${RM} ${NAME} 
re : fclean all

.PHONY : all clean fclean re
