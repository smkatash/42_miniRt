/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:51:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/29 13:41:38 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	char	findc;
	size_t	i;

	string = (char *)s;
	findc = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (string[i] == findc)
			return (string + i);
		i--;
	}
	if (string[i] == findc)
		return (string);
	return (0);
}

//if we find in array the c
//we delete the characters that were before c
//begin array from 0 and look all c in str
