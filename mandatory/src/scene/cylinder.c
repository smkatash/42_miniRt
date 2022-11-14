/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:43:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 19:35:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief sets plane parameters for cylinder
 * @return plane
 */
static t_plane	*cylinder_plane(t_point center, t_vector dir, double radius)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		error_message("Malloc error\n");
	plane->point = center;
	plane->normal = dir;
	plane->radius = radius;
	return (plane);
}

/**
 * @brief sets top plane parameters for cylinder
 */
static void	set_cylinder_top(t_scene *scene, t_cylinder *cy, t_color color)
{
	t_objlst	*new_object;
	t_plane		*top_cap;

	new_object = ft_calloc(1, sizeof(t_objlst));
	if (!new_object)
		error_message("Malloc error\n");
	push_back(&scene->objects, new_object);
	top_cap = cylinder_plane(cy->center, cy->normal, cy->radius);
	new_object->object = top_cap;
	new_object->type = PLANE;
	new_object->color = color;
}

/**
 * @brief sets bottom plane parameters for cylinder
 */
static void	set_cylinder_btm(t_scene *scene, t_cylinder *cy, t_color color)
{
	t_objlst	*new_object;
	t_vector	temp;
	t_plane		*btm_cap;

	new_object = ft_calloc(1, sizeof(t_objlst));
	if (!new_object)
		error_message("Malloc error\n");
	push_back(&scene->objects, new_object);
	multiply_scalar(&temp, &cy->normal, cy->height);
	addition(&temp, &temp, &cy->center);
	btm_cap = cylinder_plane(temp, cy->normal, cy->radius);
	new_object->object = btm_cap;
	new_object->type = PLANE;
	new_object->color = color;
}

/**
 * @brief sets cylinder parameters
 * @return cylinder
 */
void	*set_cylinder(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_cylinder	*cylinder;

	parsed_objects = objects->object;
	new_objects = ft_calloc(1, sizeof(t_objlst));
	if (!new_objects)
		error_message("Malloc error\n");
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_message("Malloc error\n");
	push_back(&scene->objects, new_objects);
	cylinder->center = get_double_vector(parsed_objects->point, 0, 0);
	cylinder->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(parsed_objects->height, 0, INFINITY);
	new_objects->type = CYLINDER;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = cylinder;
	set_cylinder_top(scene, cylinder, new_objects->color);
	set_cylinder_btm(scene, cylinder, new_objects->color);
	return (scene);
}
