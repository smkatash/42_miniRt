/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/04 21:37:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t size)
{
	char	*line;

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
