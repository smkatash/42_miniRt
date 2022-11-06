/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:44:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 14:31:42 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../gnL/get_next_line.h"

t_etexture	object_texture(char **str, int len, int i)
{
	if (ft_strcmp(str[i], "-rgb") == 0)
	{
		if (len == i + 5)
			return (COLOR);
	}
	else if (ft_strcmp(str[i], "-ck") == 0)
	{
		if (len == i + 8)
			return (CHECKBOARD);
	}
	else if (ft_strcmp(str[i], "-bmp") == 0)
	{
		if (len == i + 6 || len == i + 5)
			return (BUMPMAP);
	}
	return (UNDEF);
}

t_etexture	color_texture(int len, int i)
{
	if (len == i + 1)
		return (COLOR);
	return (UNDEF);
}

t_etexture	get_texture_type(t_parse *lst, char **str, int i)
{
	int		line_len;

	line_len = 0;
	while (str[line_len] != NULL)
		++line_len;
	if (line_len <= i)
		return (UNDEF);
	if (lst->type == SPHERE || lst->type == PLANE || lst->type == CYLINDER)
	{
		return (object_texture(str, line_len, i));
	}
	else if (lst->type == AMBIENT || lst->type == LIGHT)
		return (color_texture(line_len, i));
	return (COLOR);
}

void	set_texture_type(t_parse *lst, char **str, int i)
{
	lst->texture_ident = str[i++];
	if (lst->text_type == COLOR)
		lst->rgb = str[i++];
	else if (lst->text_type == CHECKBOARD)
	{
		lst->rgb = str[i++];
		lst->xcolor = str[i++];
		lst->xwidth = str[i++];
		lst->xheight = str[i++];
	}
	if (lst->text_type == BUMPMAP)
		lst->texture_img = str[i++];
	else
		lst->texture_img = NULL;
	if (lst->text_type == BUMPMAP && str[i + 3] != NULL)
		lst->bump_img = str[i++];
	else
		lst->bump_img = NULL;
	lst->KD = str[i++];
	lst->KS = str[i++];
	lst->KSN = str[i++];
}

static void	parse_element_type(t_parse *lst, char **str)
{
	int		i;

	lst->ident = str[0];
	lst->type = element_type_set(str[0]);
	i = 1;
	if (lst->type == NA)
		error_message("Invalid element type.\n");
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
	if (lst->type == CAMERA)
		lst->text_type = CAM;
	else
		lst->text_type = get_texture_type(lst, str, i);
	if (lst->text_type == -1)
		error_message("Invalid texture.\n");
	if (lst->type == AMBIENT || lst->type == LIGHT)
		lst->rgb = str[i++];
	else if (lst->type == SPHERE || lst->type == CYLINDER \
		|| lst->type == PLANE)
		set_texture_type(lst, str, i);
}

static void	*parse_elements(char **line)
{
	t_parse		*lst;
	char		*whitespace;
	char		**split_array;

	lst = new_parse_list();
	whitespace = " \t\v\f\r";
	split_array = ft_split_set(*line, whitespace);
	if (!split_array)
		error_message("Parse error...\n");
	else if (!split_array[0])
	{
		free(lst);
		return (free_split(split_array));
	}
	parse_element_type(lst, split_array);
	free(split_array);
	return (lst);
}

static void	parse_line(char *line, t_parse *plist, t_objlst **objects)
{
	if (line[0] != '\n')
	{
		plist = parse_elements(&line);
		if (plist)
			push_back(objects, create_list(plist, plist->type,
					(t_color){0, 0, 0}));
	}
}

void	*parse_input_file(t_objlst **objects, int fd)
{
	t_parse	*parsed_lst;
	char	*line;
	int		bytes_read;

	parsed_lst = NULL;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			bytes_read = ft_strlen(line);
			if (bytes_read == 0)
				error_message("Could not read the file\n");
			parse_line(line, parsed_lst, objects);
		}
		else
		{
			free(line);
			bytes_read = 0;
		}
	}
	if (!elements_valid_count(*objects))
		error_message("Wrong input data: ambient, light and camera.\n");
	return (*objects);
}

t_scene	*parse_input_set_scene(t_scene *scene, int fd, void	*mlx)
{
	t_objlst	*object_list;

	object_list = NULL;
	parse_input_file(&object_list, fd);
	parse_to_scene(&scene, object_list, mlx);
	free_parse_list(&object_list);
	return (scene);
}
