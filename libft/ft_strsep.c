/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:51:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 02:03:23 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char delim)
{
	char	*begin;

	begin = *stringp;
	if (begin == NULL)
		return (NULL);
	while (**stringp)
	{
		if (**stringp == delim)
		{
			**stringp = '\0';
			(*stringp)++;
			return (begin);
		}
		(*stringp)++;
	}
	*stringp = NULL;
	return (begin);
}
