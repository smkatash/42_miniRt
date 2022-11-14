# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:55:06 by aiarinov          #+#    #+#              #
#    Updated: 2022/11/12 19:07:18 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_memchr.c ft_substr.c ft_strjoin.c \
			ft_memcmp.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strtrim.c \
			ft_calloc.c ft_strdup.c ft_atoi.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
			ft_atof.c ft_strsep.c ft_strcmp.c ft_split_set.c 

BSOURCE = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

.SILENT:

all: $(NAME)

$(NAME):
	cc -Werror -Wextra -Wall $(SOURCE) -c

	ar -rc $(NAME) *.o


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	cc -Werror -Wextra -Wall $(SOURCE) $(BSOURCE) -c

	ar -rc $(NAME) *.o
