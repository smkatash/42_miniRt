/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:01 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/11 18:59:33 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief matches elements to objects
 * @return true/false
 */
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
	else if (type_data == HEIGHT && type == CYLINDER)
		return (true);
	else if (type_data == FOV && type == CAMERA)
		return (true);
	else if (type_data == RGB && \
	(type == AMBIENT || type == LIGHT || type == SPHERE || type == PLANE || \
	type == CYLINDER))
		return (true);
	return (false);
}

/**
 * @brief verifies number of elements and array length
 * @return true/false
 */
bool	scan_elements(t_form type, char **str)
{
	int		i;
	int		arr_len;

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
	arr_len = 0;
	while (str[arr_len])
		++arr_len;
	if (i != arr_len || type == NA)
		return (false);
	return (true);
}

/**
 * @brief counts ambient, light, camera elements
 * @return true for == 1, else - false
 */
bool	elements_valid_count(t_objlst *objects)
{
	int		ambient_count;
	int		light_count;
	int		camera_count;
	t_parse	*parse;

	ambient_count = 0;
	light_count = 0;
	camera_count = 0;
	while (objects)
	{
		parse = objects->object;
		if (!ft_strcmp(parse->ident, "A"))
			++ambient_count;
		else if (!ft_strcmp(parse->ident, "L"))
			++light_count;
		else if (!ft_strcmp(parse->ident, "C"))
			++camera_count;
		objects = objects->next;
	}
	if (ambient_count == 1 && light_count == 1 && camera_count == 1)
		return (true);
	return (false);
}

/**
 * @brief sets type of element
 * @return element type
 */
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
	return (NA);
}
