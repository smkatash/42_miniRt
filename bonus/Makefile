# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/11/02 22:15:22 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH 	:= src src/parse src/scene src/utils src/vector src/render

NAME 	:= minirt

SRC 	:= main.c parse_list.c parse_to_scene.c parse_utils.c parse.c \
ambient.c camera.c light.c object.c scene.c utils.c list.c getter.c \
vector_math.c vector_scalar.c vector_setter.c vector_utils.c \
color.c hittable.c ray.c render.c hit_cylinder.c hit_plane.c hit_sphere.c \
illumination.c phong_illumination_model.c vector_matrix_tbn.c \
texture_checkerboard.c texture_map.c 

OBJ 	:= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror
INCFL	:=	-I libs/libft -I include
INCGNL	:=	-I libs/libgnL -I include
LIBS	:=	libs/libft/libft.a
LIBSGNL	:=	libs/gnL/libgnL.a
RM 		:= rm -r
RMF 	:= rm -rf

.SILENT:

all: $(NAME) 

$(NAME) : $(OBJ) | $(LIBS) $(LIBSGNL)
	$(CC) $(OBJ) -Llibs/libft -lft -Llibs/gnL -lgnL -Llibs/minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[1;32m minirt is compiled \033[0m"

obj/%.o : %.c | obj
	$(CC) $(CFLAGS) $(INCFL) $(INCGNL) -c $< -o $@

obj:
	mkdir obj

$(LIBS) :
	- (cd libs/libft && make bonus && make clean)

$(LIBSGNL) :
	- (cd libs/gnL && make && make clean)

clean :
	$(RMF) obj
	@echo "deleting object files..."

fclean : clean
	$(RM) $(NAME)
	@echo "deleting compilable..."
	- (cd libs/libft && make fclean)
	- (cd libs/gnL && make fclean)

re : clean all

.PHONY:	all clean fclean re 