# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:13:49 by baubigna          #+#    #+#              #
#    Updated: 2022/02/12 16:46:00 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	so_long.c \
				./includes/ft_strlen.c \
				./includes/ft_strdup.c \
				./includes/ft_strchr.c \
				./includes/ft_substr.c \
				./includes/ft_strjoin.c \
				./includes/ft_split.c \
				./includes/get_next_line.c \
				./includes/ft_printf_utils.c \
				./includes/ft_printf.c \
				map_checker.c \
				map_creator.c \
				map_initializer.c \
				moves.c

OBJS	=	${SRCS:.c=.o}

GCC		=	gcc

GFLAGS	=	-Wall -Werror -Wextra

INCS		=	-I ./mlx_mac
LIBC		=	-L ./mlx_mac -lmlx
MLX_FLAGS	=	-Ofast -framework OpenGL -framework AppKit
MLX_USED	=	mlx_mac

all:	${NAME}

.c.o:
		@${GCC} ${GFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
				@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
				@${GCC} ${GFLAGS} ${INCS} ${LIBC} ${MLX_FLAGS} -o ${NAME} ${OBJS}

clean:
		@${MAKE} -C ${MLX_USED} clean >/dev/null
		@rm -f ${OBJS}

fclean:		clean
		@rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean re