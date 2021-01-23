# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: desausag <desausag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 13:40:25 by desausag          #+#    #+#              #
#    Updated: 2021/01/23 21:51:34 by desausag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_printf.c ft_printf_utils.c \
 			./parser/ft_parser.c \
 			./processor/ft_processor.c \
 			./processor/qx_function.c \
 			./processor/uint_function.c \
 			./processor/ptr_function.c \
 			./processor/str_function.c \
 			./processor/c_function.c \
 			./processor/int_function.c \
 			./processor/wide_proc.c \

OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BONUS:.c=.o}

NAME		= libftprintf.a
# NAME		= my_printf

CC			= gcc

RM			= rm -f

HEADER		= ft_printf.h

FLAGS		=  -Wall -Wextra -Werror

.c.o:
			${CC} $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER) libft.a
			ar rc $(NAME) $(OBJS) ./libft/*.o
			ranlib libftprintf.a

libft.a:
			(cd ./libft/.;$(MAKE))

all:		${NAME}

do_prev:	all
			$(CC) $(FLAGS) libftprintf.a -o my_printf

do:			do_prev fclean

clean:
			${RM} ${OBJS} ${BOBJS} *.out
			(cd ./libft/.;$(MAKE) clean)
			(cd ..)

fclean:		clean
			${RM} ${NAME} *.a
			(cd ./libft/.;$(MAKE) fclean)
			(cd ..)

re:			fclean all

.PHONY:		all clean fclean re