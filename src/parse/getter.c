/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:10:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/24 13:17:05 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

int	get_input_file(int argv, char **argc)
{
	char	*format;
	int		fd;
	int		filename_len;
	int		end_len;

	format = ".rt";
	if (argv != 2)
		error_message("Wrong number of arguments...\n");
	filename_len = ft_strlen(argc[1]);
	if (filename_len < 3)
		error_message("The file format should be: [filename].rt\n");
	end_len = ft_strncmp(&argc[1][filename_len - 3], format, 3);
	if (end_len != 0)
		error_message("The file format should be: [filename].rt\n");
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

double	get_double(const char *str, double min, double max)
{
	double	num;

	num = ft_atof(str);
	// if (num)
	// 	error_message("Wrong input format.\n");
	if (min == 0 && max == 0)
		return (num);
	else if (min == 0 && max == INFINITY && num < 0)
		error_message("Wrong input range.\n");
	else if (min == 0 && max == 180 && num >= 180)
		error_message("FOV range should be under 180.\n");
	else if (min == 0 && max == 180 && num < 0)
		error_message("FOV range should be over 0.\n");
	if (num < min || num > max)
		error_message("Wrong input range.\n");
	return (num);
}

static int	strtoi(char *str, int min, int max)
{
	int		num;

	num = ft_atoi(str);
	// if (!num)
	// 	error_message("Wrong input parameters.\n");
	if (num < min || num > max)
		error_message("Wrong input range.\n");
	return (num);
}

struct s_vec3	get_int_vector(char *str, int min, int max)
{
	struct s_vec3	new_vector;
	char			*temp;
	char			*ptr;

	temp = ft_strdup(str);
	ptr = temp;
	new_vector.x = strtoi(ft_strsep(&temp, ','), min, max);
	new_vector.y = strtoi(ft_strsep(&temp, ','), min, max);
	new_vector.z = strtoi(ft_strsep(&temp, ','), min, max);
	if (ft_strsep(&temp, ',') != NULL)
		error_message("Wrong input parameters.\n");
	if (min == 0 && max == 255)
		divide_scalar(&new_vector, &new_vector, 255);
	free(ptr);
	return (new_vector);
}

struct s_vec3	get_double_vector(char *str, double min, double max)
{
	struct s_vec3	new_vector;
	char			*temp;
	char			*ptr;

	temp = ft_strdup(str);
	ptr = temp;
	new_vector.x = get_double(ft_strsep(&temp, ','), min, max);
	new_vector.y = get_double(ft_strsep(&temp, ','), min, max);
	new_vector.z = get_double(ft_strsep(&temp, ','), min, max);
	if (ft_strsep(&temp, ',') != NULL)
		error_message("Wrong input parameters.\n");
	if (min == -1 && max == 1)
	{
		if (length(&new_vector) == 0.0)
			error_message("Wrong input range: normalized vector is zero\n");
		unit_vector(&new_vector, &new_vector);
	}
	else if (min == 0 && max == 255)
		divide_scalar(&new_vector, &new_vector, 255);
	free(ptr);
	return (new_vector);
}

static int	find_start(char const *s, char *cset, size_t index)
{
	char	*cs;

	cs = cset;
	while (*cs != '\0')
	{
		if (index == 0 && *s == *cs)
			return (0);
		else if (index > 0 && s[index - 1] == *cs)
		{
			while (*cset != '\0')
			{
				if (s[index] == *cset)
					return (0);
				++cset;
			}
			return (1);
		}
		++cs;
	}
	if (index == 0)
		return (1);
	return (0);
}

static int	find_end(char const *s, char *cset, size_t index)
{
	char	*cs;

	cs = cset;
	while (*cs != '\0')
	{
		if (s[index] == *cs)
			return (0);
		++cs;
	}
	while (*cset != '\0')
	{
		if (s[index + 1] == *cset || s[index + 1] == 0)
			return (1);
		++cset;
	}
	return (0);
}

static char	*word_maker(char const *s, char *charset, size_t *i)
{
	char	*word;
	size_t	size;

	size = 0;
	while (!find_start(s, charset, *i))
		*i += 1;
	while (!find_end(s, charset, *i + size))
		size++;
	word = (char *)malloc(size + 2);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*i], size + 2);
	*i = *i + size + 1;
	return (word);
}

static char	**free_book(char **book, size_t index)
{
	while (index > 0)
		free(book[--index]);
	free(book);
	return (NULL);
}

char	**ft_splitter(char const *s, char *charset)
{
	char	**book;
	size_t	i;
	size_t	num;
	size_t	index;

	i = 0;
	num = 0;
	index = 0;
	if (!s)
		return (NULL);
	while (s[i])
		if (find_end(s, charset, i++))
			num++;
	book = (char **)malloc(sizeof(char *) * (num + 1));
	if (!book)
		return (NULL);
	i = 0;
	while (index < num)
	{
		book[index] = word_maker(s, charset, &i);
		if (!book[index++])
			return (free_book(book, index));
	}
	book[num] = NULL;
	return (book);
}