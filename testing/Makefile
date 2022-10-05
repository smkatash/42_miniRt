# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 09:01:25 by kanykei           #+#    #+#              #
#    Updated: 2022/10/05 22:52:15 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	src
NAME = miniRT

SRC = main.c colors.c vec3.c camera.c sphere.c

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = vec3.h
RM = rm -r
RMF = rm -rf

all: ${NAME}

${NAME} : ${OBJ} ${HEADER}
	@${CC} ${OBJ} -o ${NAME}
	@echo "miniRT is compiled"
	
obj/%.o: %.c | obj
	@${CC} ${CFLAGS} -c $< -o $@ 

obj:
	@mkdir obj

clean:
	@${RMF} obj
	@echo "\033[1;32m object files deleted \033[0m"

fclean: clean
	@${RM} ${NAME}
	@echo "\033[1;32m executable deleted \033[0m"

re: fclean all

image: ${NAME}
	./${NAME} > image.ppm

.PHONY:	all clean fclean re image