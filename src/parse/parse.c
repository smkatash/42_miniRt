/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:44:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 23:41:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../gnL/get_next_line.h"

static t_form	element_type_set(char *s)
{
	if (ft_strcmp(s, "A"))
		return (AMBIENT);
	else if (ft_strcmp(s, "C"))
		return (CAMERA);
	else if (ft_strcmp(s, "L"))
		return (POINT_LIGHT);
	else if (ft_strcmp(s, "sp"))
		return (SPHERE);
	else if (ft_strcmp(s, "pl"))
		return (PLANE);
	else if (ft_strcmp(s, "cy"))
		return (CYLINDER);
	return (NA);
}

static void	parse_element_type(t_parse *lst, char **str)
{
	int		i;

	i = 1;
	lst->ident = str[0];
	lst->type = element_type_set(str[0]);
	if (lst->type == NA)
		error_message("Invalid element type.\n");
	if (scan_elements(lst->type, str) == FALSE)
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

static t_parse	*parse_elements(char *line)
{
	t_parse		*lst;
	char		*whitespace;
	char		**split_array;

	lst = new_parse_list();
	whitespace = " \t\v\f\r";
	split_array = ft_split(line, *whitespace);
	if (split_array == NULL)
		error_message("Parse error...\n");
	else if (split_array[0] == NULL)
	{
		free(lst);
		return (free_split(split_array));
	}
	parse_element_type(lst, split_array);
	free(split_array);
	return (lst);
}

t_objlst	*parse_input_file(t_objlst *objects, int fd)
{
	t_parse		*parsed_lst;
	char		*line;
	int 	    bytes_read;

	objects = NULL;
	parsed_lst = NULL;
	bytes_read = TRUE;
	while (bytes_read == TRUE)
	{
		line = get_next_line(fd);
		bytes_read = ft_strlen(line);
		if (bytes_read == FALSE)
			error_message("Could not read the file\n");
		parsed_lst = parse_elements(line);
		if (parsed_lst != NULL)
			push_back(&objects, \
			create_list(parsed_lst, 0, (t_color){0, 0, 0}));
		if (line != NULL)
			free(line);
	}
	if (elements_valid_count(objects) == FALSE)
		error_message("Wrong input data: ambient, light and camera.\n");
	return (objects);
}