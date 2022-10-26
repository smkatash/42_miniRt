/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:08:38 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/31 10:53:56 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*newstring;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (len1 + len2 +1));
	if (!newstring)
		return (NULL);
	while (i < len1)
		newstring[j++] = s1[i++];
	i = 0;
	while (i < len2)
		newstring[j++] = s2[i++];
	newstring[j] = '\0';
	return (newstring);
}
