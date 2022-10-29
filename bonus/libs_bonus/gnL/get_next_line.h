/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:46:26 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 14:46:43 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*ft_strjoin_gnL(char *s1, char *s2);
char	*ft_strchr_gnL(char *s, int c);
char	*ft_strdup_gnL(char *src);
char	*get_next_line(int fd);

#endif