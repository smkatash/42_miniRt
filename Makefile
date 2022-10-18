# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/10/18 13:40:28 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src/parse src/scene src/objectlist src/vector src
NAME = minirt

SRC = main.c parse_list.c parse_to_scene.c parse_utils.c parsing.c \
ambient.c camera.c light.c object.c scene.c errors.c list.c getter.c \
vector_math.c vector_scalar.c vector_setter.c vector_utils.c 

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCFL	=	-I libft -I include
INCGNL	=	-I libgnL -I include
LIBS	=	libft/libft.a
LIBSGNL	=	gnL/libgnL.a
RM = rm -r
HEADER	= include/*
RMF = rm -rf

all: $(NAME)

$(NAME) : $(OBJ) | $(LIBS) | $(LIBSGNL)
	$(CC) $(OBJ) -Llibft -lft -LgnL -lgnL -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;32m minirt is compiled \033[0m"

obj/%.o : %.c | obj
	$(CC) $(CFLAGS) $(INCFL) $(INCGNL) -c $< -o $@

obj:
	@mkdir obj

$(LIBS) :
	- (cd libft && make bonus && make clean)

$(LIBSGNL) :
	- (cd gnL && make && make clean)

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)
	-(cd gnL && make fclean)

re : clean all

.PHONY:	all clean fclean re 