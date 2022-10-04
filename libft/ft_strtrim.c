/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:40:40 by aiarinov          #+#    #+#             */
/*   Updated: 2022/03/30 14:14:21 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_char_set(s1[start], set) != 0)
		start++;
	while (end > start && ft_char_set(s1[end - 1], set) != 0)
		end--;
	dest = malloc(sizeof(char) * (end - start) + 1);
	if (!dest)
		return (NULL);
	while (end > start)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

//line 40 end - 1 because of '\0'
//line 42 end - start we become what we have in str
//  between start and end
// #include <stdio.h>

// int main()
// {
// 	char *str;
// 	char *value;
// 	char *res;

// 	str = "cccfghjgcc";
// 	value = "c";
// 	res = ft_strtrim (str, value);
// 	printf ("%s", res);
// 	return (0);
// }
