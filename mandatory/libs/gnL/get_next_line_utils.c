/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:45:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 14:35:51 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
	{
		return ((char *)&s[i]);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup_gnl(char *src)
{
	size_t	len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	dest = malloc(len + 1);
	i = 0;
	if (dest == 0)
		return (0);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

static void	ft_strlcpy_d(char *str, char *s1, char *s2, size_t pref)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = pref;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[count] = s2[i];
		i++;
		count++;
	}
	str[count] = '\0';
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	pref;
	size_t	suff;
	char	*str;

	if (!s1)
		s1 = ft_strdup_gnl("");
	if (!s1 || !s2)
		return (NULL);
	pref = ft_strlen(s1);
	suff = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (pref + suff + 1));
	if (str)
	{
		ft_strlcpy_d(str, (char *)s1, (char *)s2, pref);
		free(s1);
		return (str);
	}
	return (NULL);
}
