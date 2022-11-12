/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:10:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/11 15:44:44 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief checks .rt format, opens a filepath
 * @return a file descriptor
 */
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

/**
 * @brief converts a string to float, verifies limit range min/max
 * @return float
 */
double	get_double(const char *str, double min, double max)
{
	double	num;

	num = ft_atof(str);
	if (num > DBL_MAX || num < -DBL_MAX)
		error_message("Wrong input format.\n");
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

/**
 * @brief converts a string to integer, verifies limit range min/max
 * @return integer
 */
static int	strtoi(char *str, int min, int max)
{
	int		num;

	num = ft_atoi(str);
	if (num > INT_MAX || INT_MIN > num)
		error_message("Wrong input format.\n");
	if (num < min || num > max)
		error_message("Wrong input range.\n");
	return (num);
}

/**
 * @brief converts a string to integer with delimiter separation, 
 * verifies limit range min/max, converts color to vector format
 * @return color (vector format)
 */
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

/**
 * @brief converts a string to integer with delimiter separation, 
 * verifies limit range min/max, converts color to vector format
 * @return color (vector format)
 */
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
