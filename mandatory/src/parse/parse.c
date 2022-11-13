/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:44:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 23:01:08 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief parses object types from file descriptor 
 * @return parsed list
 */
static void	parse_element_type(t_parse *lst, char **str)
{
	int		i;

	lst->ident = str[0];
	lst->type = element_type_set(str[0]);
	i = 1;
	if (scan_elements(lst->type, str) == false)
		error_message("Invalid element type.\n");
	if (valid_type(lst->type, POINT))
		lst->point = str[i++];
	if (valid_type(lst->type, BRI_RATIO))
		lst->bri_ratio = str[i++];
	if (valid_type(lst->type, NORM_VEC))
		lst->nor_vec = str[i++];
	if (valid_type(lst->type, DIAMETER))
		lst->diameter = str[i++];
	if (valid_type(lst->type, HEIGHT))
		lst->height = str[i++];
	if (valid_type(lst->type, FOV))
		lst->fov = str[i++];
	if (valid_type(lst->type, RGB))
		lst->rgb = str[i++];
}

/**
 * @brief parses line from file descriptor
 * @return parsed list
 */
static t_parse	*parse_elements(char **line)
{
	t_parse		*p_object;
	char		**split_array;

	p_object = new_parse_list();
	split_array = ft_split_set(*line, " \t\v\f\r");
	if (!split_array)
		error_message("Parse error...\n");
	else if (split_array[0] == NULL)
	{
		free(p_object);
		return (free_split(split_array));
	}
	parse_element_type(p_object, split_array);
	free(split_array);
	return (p_object);
}

/**
 * @brief parses line from file descriptor
 * @return object list
 */
static void	parse_line(char *line, t_parse *data, t_objlst **objects)
{
	if (line[0] != '\n')
	{
		data = parse_elements(&line);
		if (data != NULL)
		{
			push_back(objects, create_list(data, data->type,
					(t_color){0, 0, 0}));
		}
	}
}

/**
 * @brief parses line from file descriptor
 * @return object list
 */
static void	*parse_input_file(t_objlst **objects, int fd)
{
	t_parse	*data;
	char	*line;
	int		bytes_read;

	data = NULL;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			bytes_read = ft_strlen(line);
			if (bytes_read == 0)
				error_message("Could not read the file\n");
			parse_line(line, data, objects);
			free(line);
		}
		else
			bytes_read = 0;
	}
	return (*objects);
}

/**
 * @brief parses, sets object list to scene
 * @return object list
 */
t_scene	*parse_input_set_scene(t_scene *scene, int fd)
{
	t_objlst	*object_list;

	object_list = NULL;
	parse_input_file(&object_list, fd);
	if (elements_valid_count(object_list) == false)
		error_message("Wrong input data: ambient, light and camera.\n");
	parse_to_scene(&scene, object_list);
	free_parse_list(&object_list);
	return (scene);
}
