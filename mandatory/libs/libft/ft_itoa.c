/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaiarinovskaia <annaiarinovskaia@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:07:04 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/16 15:45:15 by annaiarinov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	num;
	int	count;

	num = n;
	count = 0;
	while (num != '\0')
	{
		num = num / 10;
		count++;
	}
	count = count + (n <= 0);
	return (count);
}

static char	*exist(int n)
{
	char	*str;
	int		counter;

	counter = count(n);
	str = (char *)malloc(sizeof(char) * (counter + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		counter;
	char	*str;

	sign = 1;
	counter = count(n);
	if (n < 0)
		sign = -1;
	str = exist(n);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[counter] = '\0';
	while (n != '\0')
	{
		str[--counter] = (char)((n % 10) * sign + '0');
		n = n / 10;
	}
	counter--;//counter-- equal str[counter - 1]
	if (sign < 0)
		str[counter] = '-';
	return (str);
}
