# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/10/21 00:02:10 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src src/parse src/scene src/objectlist src/vector src/render

SRC = main.c parse_list.c parse_to_scene.c parse_utils.c parse.c \
ambient.c camera.c light.c object.c scene.c errors.c list.c getter.c \
vector_math.c vector_scalar.c vector_setter.c vector_utils.c \
color.c hittable.c ray.c render.c hit_cylinder.c hit_plane.c hit_sphere.c

NAME = minirt

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCFL	=	-I libft -I include
INCGNL	=	-I libgnL -I include
LIBS	=	libft/libft.a
LIBSGNL	=	gnL/libgnL.a
RM = rm -r
RMF = rm -rf

all: $(NAME)

$(NAME) : $(OBJ) $(LIBS) $(LIBSGNL)
	@$(CC) $(OBJ) -Llibft -lft -LgnL -lgnL -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;32m minirt is compiled \033[0m"

obj/%.o : %.c | obj
	@$(CC) $(CFLAGS) $(INCFL) $(INCGNL) -c $< -o $@

obj:
	@mkdir obj

$(LIBS) :
	@- (cd libft && make bonus && make clean)

$(LIBSGNL) :
	@- (cd gnL && make && make clean)
	@echo "compiling libraries..."

clean :
	@rm -rf obj
	@echo "deleting object files..."

fclean : clean
	@rm -f $(NAME)
	@echo "deleting compilable..."
	@- (cd libft && make fclean)
	@- (cd gnL && make fclean)
	@echo "deleting libraries..."

re : clean all

.PHONY:	all clean fclean re 