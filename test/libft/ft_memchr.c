/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:55:04 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 17:33:41 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	string = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*string == (unsigned char)c)
		{
			return ((void *)string);
		}
		i++;
		string++;
	}
	return (NULL);
}

//searching for the first matching of the char c in the first n bytes
// and return everything what after that char
