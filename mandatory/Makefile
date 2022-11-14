# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:29:40 by aiarinov          #+#    #+#              #
#    Updated: 2022/11/14 19:58:47 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Target =================================== #
NAME		:= miniRT

# ================================ Sources =================================== #

VPATH		:= src src/parse src/scene src/utils src/vector src/render

SRC			:= main.c parse_list.c parse_to_scene.c parse_utils.c parse.c \
ambient.c camera.c light.c plane_sphere.c cylinder.c scene.c utils.c list.c getter.c \
vector_math.c vector_scalar.c vector_setter.c vector_utils.c \
color.c hittable.c ray.c render.c hit_cylinder.c hit_plane.c hit_sphere.c \
illumination.c phong_illumination_model.c

# ================================ Flags ===================================== #
OBJ			:= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC			:= cc
CFLAGS 		:= -Wall -Wextra -Werror #-fsanitize=address
MLXFLAGS	:=	-framework OpenGL -framework AppKit
RM			:= rm -r
RMF			:= rm -rf

# ============================== Libraries ==================================== #
INCFL		:=	-I./include -I./libs/libft -I./libs/gnL -I./libs/minilibx
LIBS		:=	-L./libs/libft -lft -L./libs/gnL -lgnL -L./libs/minilibx -lmlx -lz
LIBSLIBFT	:=	libs/libft/libft.a
LIBSGNL		:=	libs/gnL/libgnL.a
LIBSMLX		:=	libs/minilibx/libmlx.a

# ================================ Rules ===================================== #
.SILENT:

all: $(NAME) 

$(NAME)		: $(OBJ) $(LIBSMLX) $(LIBSLIBFT) $(LIBSGNL)
			$(CC) $(OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
			@echo "\033[1;32m miniRT is compiled \033[0m"

obj/%.o		: %.c | obj
			$(CC) $(CFLAGS) $(INCFL) -c $< -o $@

obj			:
			mkdir obj

$(LIBSLIBFT):
			- (cd libs/libft && make bonus && make clean)

$(LIBSGNL)	:
			- (cd libs/gnL && make && make clean)

$(LIBSMLX)	:
			- (cd libs/minilibx && make && make clean)

clean		:
			$(RMF) obj
			@echo "deleting object files..."

fclean		: clean
			$(RM) $(NAME)
			@echo "deleting compilable..."
			- (cd libs/libft && make fclean)
			- (cd libs/gnL && make fclean)
			- (cd libs/minilibx && make fclean)

re			: clean all

.PHONY		:	all clean fclean re 