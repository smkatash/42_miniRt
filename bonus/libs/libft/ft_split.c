/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:14:30 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/04 16:31:03 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char delim)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == delim)
			i++;
		else
		{
			words++;
			while (str[i] != '\0' && str[i] != delim)
				i++;
		}
	}
	return (words);
}

static char	*word_length(const char **s, char c)
{
	int			i;
	char		*word;
	const char	*str;

	str = *s;
	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_word(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**str;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		str[i] = word_length(&s, c);
		if (str[i] == NULL)
			free_word(i, str);
		while (*s && *s != c)
			s++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

//line 37 because we send the copy from another function,
//   that already have been used
//line69 clean the whole massiv
//line89 &s because we need the adress from the string and not the value,
//   we put in every i the new word
