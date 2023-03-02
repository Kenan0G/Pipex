# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 10:43:48 by kgezgin           #+#    #+#              #
#    Updated: 2023/02/28 11:41:49 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
SRCS		=	main.c\
				path.c\
				list.c\
				forks.c\
				parsing.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
NAME			=	pipex
CC				=	gcc
CFLAGS			=	-g3
RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd ft_libft && make && cd ../ft_printf && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ft_libft/libft.a ft_printf/libftprintf.a

all:		${NAME}

clean:	
	cd ft_libft && make fclean && cd ../ft_printf && make fclean
	${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re