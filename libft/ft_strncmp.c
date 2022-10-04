/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:13:09 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/28 14:01:11 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0'
		&& i < n - 1 && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

//compare two strings and return the difference between them

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//    char str1[20]="hello";
//    char str2[20]="helLO WORLD";
//    int result;

//    result = strncmp(str1, str2, 5);

//    printf("the    strncmp is : %d \n", result);
//    //ft_strncmp(str1, str2, 5);
//    printf("the ft_strncmp is : %d \n", ft_strncmp(str1, str2, 5));

//    return (0);
// }
