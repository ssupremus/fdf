# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 19:00:32 by ysushkov          #+#    #+#              #
#    Updated: 2018/08/06 12:06:10 by ysushkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

FLAGS	:=	-Wall -Werror -Wextra

SRC		:=	main.c structures.c build.c format.c \
			tablecolors.c drawning.c deal_key.c

LIB		:=	./libft/libft.a

FLG		:= -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(SRC)
	make -C libft
	cc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(FLG)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re
