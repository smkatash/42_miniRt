/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:06:17 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/29 16:48:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	res;
	size_t	len_src;
	size_t	i;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	res = 0;
	i = 0;
	if (size == 0)
		return (len_src);
	if (size > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + size;
	while (s[i] && len_dst < size - 1)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
		dst[len_dst] = '\0';
	}
	return (res);
}

//combine two strings together
//line 22 count of dst
// line 28 if for example dst[i] = 5 than src[j] = 0,
//  that's why we add j++ and i++

// int main()
// {
// 	char dest[100];
// 	memset(dest, 0x00, 99);
// 	dest[0] = '1';
// 	char *src = "5678";
// 	ft_strlcat (dest, src, 5);
// 	printf ("%s", dest);
// 	return(0);
// }
