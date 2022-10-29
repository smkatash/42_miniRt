/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:33:33 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/06 17:31:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(*s) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

//returns a substring from the str s. the substring begins at index
// start and is of max size len
// int main()
// {
// 	char *str;
// 	char *buf;
// 	int start;
// 	int len;

// 	str = "sjghsjh";
// 	start = 2;
// 	len = 5;
// 	buf = ft_substr(str, start, len);
// 	printf ("%s", buf);
// 	return (0);
// }
