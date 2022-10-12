/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 14:23:23 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t size)
{
	size_t	i;
	char	*line;

	i = 0;
	line = (char *)str;
	while (size > 0)
	{
		line[size - 1] = value;
		size--;
	}
	return (str);
}

//replace the character with value

// #include <stdio.h>
// #include <string.h>

// int main () {
//    char str[50];

//    strcpy(str,"This is string.h library function");
//    puts(str);

//    ft_memset(str,'$',7);
//    puts(str);

//    return(0);
// }
