/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:33:33 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/12 13:55:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*substr;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len_s - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((len_s - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
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
