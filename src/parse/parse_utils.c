/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:01 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/25 10:45:37 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

bool	valid_type(t_form type, t_type_data type_data)
{
	if (type_data == POINT && \
	(type == CAMERA || type == LIGHT || type == SPHERE || type == PLANE || \
	type == CYLINDER))
		return (true);
	else if (type_data == BRI_RATIO && (type == AMBIENT || type == LIGHT))
		return (true);
	else if (type_data == NORM_VEC && (type == CAMERA || type == PLANE
			|| type == CYLINDER))
		return (true);
	else if (type_data == DIAMETER && (type == SPHERE || type == CYLINDER))
		return (true);
	else if (type_data == HEIGHT && (type == CYLINDER))
		return (true);
	else if (type_data == FOV && (type == CAMERA))
		return (true);
	else if (type_data == RGB && \
	(type == AMBIENT || type == LIGHT || type == SPHERE || type == PLANE || \
	type == CYLINDER))
		return (true);
	return (false);
}

bool	scan_elements(t_form type, char **str)
{
	int		i;
	int		j;

	i = 1;
	if (valid_type(type, POINT))
		++i;
	if (valid_type(type, BRI_RATIO))
		++i;
	if (valid_type(type, NORM_VEC))
		++i;
	if (valid_type(type, DIAMETER))
		++i;
	if (valid_type(type, HEIGHT))
		++i;
	if (valid_type(type, FOV))
		++i;
	if (valid_type(type, RGB))
		++i;
	j = 0;
	while (str[j])
		++j;
	if (i != j)
		return (false);
	return (true);
}

bool	elements_valid_count(t_objlst *objects)
{
	int		ambinet_count;
	int		light_count;
	int		camera_count;
	t_parse	*parse;

	ambinet_count = 0;
	light_count = 0;
	camera_count = 0;
	while (objects)
	{
		parse = objects->object;
		if (!ft_strcmp(parse->ident, "A"))
			++ambinet_count;
		else if (!ft_strcmp(parse->ident, "L"))
			++light_count;
		else if (!ft_strcmp(parse->ident, "C"))
			++camera_count;
		objects = objects->next;
	}
	if (ambinet_count == 1 && light_count == 1 && camera_count == 1)
		return (true);
	return (false);
}
