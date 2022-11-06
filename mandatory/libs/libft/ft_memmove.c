/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:56:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/04 21:36:46 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)str1;
	source = (char *)str2;
	if (dest == NULL && source == NULL)
		return (NULL);
	if (source < dest)
	{
		while (n > 0)
		{
			dest[n - 1] = source[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, source, n);
	return (str1);
}

//coppy n char from str2 to str1 but before copying,
// first copy to the temporary array, so it prevents from overfloating
//line 30 because in array we have dest[0] and we need to copy 1 element,
// so n-1 = 0. dest[n-1] we don't have '=' so n doesnt become the amount 1
