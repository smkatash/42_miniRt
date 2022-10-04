/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:08 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 14:55:22 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*buf;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(str1);
	buf = malloc(sizeof(char) * size + 1);
	if (buf == NULL)
		return (NULL);
	while (str1[i])
	{
		buf[i] = str1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

//make a copy of str1
//copy str1 in buf
//ft_strlcpy (buf, str1, size);
