/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:50:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 13:20:27 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

//till i smaller than n we change the character on 0 (line 24)
// #include <stdlib.h>
// #include <string.h>

// int main( void )
//   {
//     char *buffer;
// 	buffer = "fnjnrknkj";
//     ft_bzero( buffer, 80 );
//     return (0);
//   }
