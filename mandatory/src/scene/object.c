/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/25 10:23:48 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	*set_sphere(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_sphere	*sphere;

	parsed_objects = objects->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
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
		return (NULL);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	push_back(&scene->objects, new_objects);
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	new_objects->type = PLANE;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = plane;
	return (scene);
}

void	*set_cylinder(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_cylinder	*cylinder;

	parsed_objects = objects->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	push_back(&scene->objects, new_objects);
	cylinder->center = get_double_vector(parsed_objects->point, 0, 0);
	cylinder->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(parsed_objects->height, 0, INFINITY);
	new_objects->type = CYLINDER;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = cylinder;
	return (scene);
}
