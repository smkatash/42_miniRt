/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:01 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 14:43:56 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	valid_type(t_form type, t_type_data type_data)
{
	if (type_data == POINT && \
	(type == CAMERA || type == LIGHT || type == SPHERE || type == PLANE || \
	type == CYLINDER || type == HYPER))
		return (true);
	else if (type_data == BRI_RATIO && (type == AMBIENT || type == LIGHT))
		return (true);
	else if (type_data == NORM_VEC && (type == CAMERA || type == PLANE
			|| type == CYLINDER || type == HYPER))
		return (true);
	else if (type_data == DIAMETER && (type == SPHERE || type == CYLINDER || type == HYPER))
		return (true);
	else if (type_data == HEIGHT && (type == CYLINDER || type == HYPER))
		return (true);
	else if (type_data == FOV && (type == CAMERA))
		return (true);
	else if (type_data == RGB && (type == AMBIENT || type == LIGHT))
		return (true);
	else if ((type_data == KD || type_data == KS || type_data == KSN) && \
	(type == SPHERE || type == PLANE || type == CYLINDER || type == HYPER))
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
	j = 0;
	while (str[j])
		++j;
	if (i > j)
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
	if (ambinet_count == 1 && light_count >= 1 && camera_count == 1)
		return (true);
	return (false);
}

t_form	element_type_set(char *s)
{
	if (!ft_strcmp(s, "A"))
		return (AMBIENT);
	else if (!ft_strcmp(s, "C"))
		return (CAMERA);
	else if (!ft_strcmp(s, "L"))
		return (LIGHT);
	else if (!ft_strcmp(s, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(s, "pl"))
		return (PLANE);
	else if (!ft_strcmp(s, "cy"))
		return (CYLINDER);
	else if (!ft_strcmp(s, "hp"))
		return (HYPER);
	return (NA);
}
