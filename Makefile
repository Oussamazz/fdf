# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2019/11/05 22:01:22 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =  src/ft_check.c src/main.c src/draw_line.c src/key.c src/rotation.c src/free.c src/ft_error.c src/inc_value.c src/menu.c
OBJ = $(SRC:%.c=%.o)
LIBF = libft/libft.a

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -L libft/ -lft  -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	make fclean -C libft/

fclean: clean
	rm -rf $(NAME)

re: fclean all
	make re -C libft/

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
