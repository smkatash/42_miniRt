# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/10/25 01:40:30 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH 	:= src src/parse src/scene src/utils src/vector src/render

NAME 	:= minirt

SRC 	:= main.c parse_list.c parse_to_scene.c parse_utils.c parse.c \
ambient.c camera.c light.c object.c scene.c utils.c list.c getter.c \
vector_math.c vector_scalar.c vector_setter.c vector_utils.c \
color.c hittable.c ray.c render.c hit_cylinder.c hit_plane.c hit_sphere.c \
illumination.c phong_illumination_model.c

OBJ 	:= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror -fsanitize=address
INCFL	:=	-I libft -I include
INCGNL	:=	-I libgnL -I include
LIBS	:=	libft/libft.a
LIBSGNL	:=	gnL/libgnL.a
RM 		:= rm -r
RMF 	:= rm -rf

.SILENT:

all: $(NAME) 

$(NAME) : $(OBJ) | $(LIBS) $(LIBSGNL)
	$(CC) $(OBJ) -Llibft -lft -LgnL -lgnL -L ./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address
	@echo "\033[1;32m minirt is compiled \033[0m"

obj/%.o : %.c | obj
	$(CC) $(CFLAGS) $(INCFL) $(INCGNL) -c $< -o $@

obj:
	mkdir obj

$(LIBS) :
	- (cd libft && make bonus && make clean)

$(LIBSGNL) :
	- (cd gnL && make && make clean)

clean :
	$(RMF) obj
	@echo "deleting object files..."

fclean : clean
	$(RM) $(NAME)
	@echo "deleting compilable..."
	- (cd libft && make fclean)
	- (cd gnL && make fclean)

re : clean all

.PHONY:	all clean fclean re 