# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 10:43:48 by kgezgin           #+#    #+#              #
#    Updated: 2023/05/02 10:06:05 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
BONUS_DIR	= ./srcs_bonus
SRCS		=	main.c\
				path.c\
				forks.c\
				here_doc.c\
				pipex_utils.c
BONUS_SRCS	=	main_bonus.c\
				path_bonus.c\
				forks_bonus.c\
				here_doc_bonus.c\
				pipex_utils_bonus.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
BONUS_OBJS		=	$(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:%.c=%.o))
NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd ft_libft && make && cd ../ft_printf && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ft_libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all:		${NAME}

clean:	
	cd ft_libft && make fclean && cd ../ft_printf && make fclean
	${RM} ${OBJS} ${BONUS_OBJS}

bonus:		$(BONUS_OBJS)
	cd ft_libft && make && cd ../ft_printf && make
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) ft_libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	
fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re