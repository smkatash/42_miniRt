/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:08:27 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 13:51:46 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_char(char const *s, char *charset, size_t pos)
{
	char	*ptr;

	ptr = charset;
	while (*ptr != '\0')
	{
		if (pos == 0 && *s == *ptr)
			return (0);
		else if (pos > 0 && s[pos - 1] == *ptr)
		{
			while (*charset != '\0')
			{
				if (s[pos] == *charset)
					return (0);
				++charset;
			}
			return (1);
		}
		++ptr;
	}
	if (pos == 0)
		return (1);
	return (0);
}

static int	last_char(char const *s, char *charset, size_t pos)
{
	char	*ptr;

	ptr = charset;
	while (*ptr != '\0')
	{
		if (s[pos] == *ptr)
			return (0);
		++ptr;
	}
	while (*charset != '\0')
	{
		if (s[pos + 1] == *charset || s[pos + 1] == 0)
			return (1);
		++charset;
	}
	return (0);
}

static char	*join_string(char const *s, char *charset, size_t *i)
{
	char	*str;
	size_t	size;

	size = 0;
	while (!first_char(s, charset, *i))
		*i += 1;
	while (!last_char(s, charset, *i + size))
		size++;
	str = (char *)malloc(size + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[*i], size + 2);
	*i = *i + size + 1;
	return (str);
}

static char	**free_array(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_split_set(char const *s, char *charset)
{
	char	**arr;
	size_t	i;
	size_t	len;
	size_t	pos;

	i = 0;
	len = 0;
	pos = 0;
	if (!s)
		return (NULL);
	while (s[i])
		if (last_char(s, charset, i++))
			len++;
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (pos < len)
	{
		arr[pos] = join_string(s, charset, &i);
		if (!arr[pos++])
			return (free_array(arr, pos));
	}
	arr[len] = NULL;
	return (arr);
}
