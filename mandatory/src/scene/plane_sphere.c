/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/10 16:44:12 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*set_sphere(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_sphere	*sphere;

	parsed_objects = objects->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		error_message("Malloc error\n");
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		error_message("Malloc error\n");
	push_back(&scene->objects, new_objects);
	sphere->center = get_double_vector(parsed_objects->point, 0, 0);
	sphere->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	new_objects->type = SPHERE;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = sphere;
	return (scene);
}

void	*set_plane(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_plane		*plane;

	parsed_objects = objects->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		error_message("Malloc error\n");
	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_message("Malloc error\n");
	push_back(&scene->objects, new_objects);
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	plane->radius = INFINITY;
	new_objects->type = PLANE;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = plane;
	return (scene);
}
