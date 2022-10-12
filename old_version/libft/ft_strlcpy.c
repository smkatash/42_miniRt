/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:51:21 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/29 10:54:13 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int		main(void)
// {
// 	char	dest[50];
// 	char	*src;
// 	int		size;

// 	src = "ceci et un test tu voissss";
// 	size = 10;
// 	printf("%d\n", ft_strlcpy(dest, src, size));
// 	printf(".%s.\n\n", dest);
// 	printf("%lu\n", strlcpy(dest, src, size));
// 	printf(".%s.\n\n", dest);
// }
