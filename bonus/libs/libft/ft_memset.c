/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:54 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/30 22:08:07 by kanykei          ###   ########.fr       */
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
