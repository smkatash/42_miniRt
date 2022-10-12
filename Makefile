# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/10/12 16:39:42 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	src
NAME = minirt

SRC = main.c get_input_file.c parse_list.c parse_to_scene.c parse_utils.c parsing.c \
ambient.c camera.c light.c object.c scene.c errors.c

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = cc
CFLAGS = -Wall -Wextra -Werror 
HEADERS = include/*.h
RM = rm -r
RMF = rm -rf

all: ${NAME}

${NAME} : ${OBJ} ${HEADERS}
	@make -C ./libft
	@make -C ./gnL
	@make -C ./minilibx
	@cc $(OBJ) /libft/libft.a ./gnL/libgnL.a -o minirt  $(FLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;32m minirt is compiled \033[0m"

obj/%.o: %.c | obj
	@${CC} ${CFLAGS} -c $< -o $@ 

obj:
	@mkdir obj

clean:
	@${RMF} obj
	@echo "object files are deleted"

fclean: clean
	@${RM} ${NAME}
	@echo "executable is deleted"

re: fclean all

.PHONY:	all clean fclean re 