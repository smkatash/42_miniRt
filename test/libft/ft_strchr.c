/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:43:17 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/06 15:29:54 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str1;
	char	c2;

	i = 0;
	c2 = (char)c;
	str1 = (char *)str;
	while ((str1[i] != c2) && (str1[i] != '\0'))
		i++;
	if (str1[i] == c2)
	{
		str1 = str1 + i;
		return (str1);
	}
	return (NULL);
}

//The strchr() function locates the first occurrence of c
// (converted to a char) in the string pointed to by s
