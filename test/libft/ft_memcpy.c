/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:50:40 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 13:21:07 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)dest;
	str2 = (char *)src;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (n == 0)
		return (str1);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}

//copies n object from src to dest

// #include <string.h>

// int		main(void)
// {
// 	write(1, "ft_memcpy\n", 10);
// 	ft_memcpy(NULL, NULL, 0);
// 	write(1, "memcpy\n", 7);
// 	memcpy(NULL, NULL, 0);
// }
