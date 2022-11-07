/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 00:41:54 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*set_sphere(t_parse *parsed_objects)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = get_double_vector(parsed_objects->point, 0, 0);
	sphere->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	sphere->kd = get_double(parsed_objects->KD, 0, 1);
	sphere->ks = get_double(parsed_objects->KS, 0, 1);
	sphere->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (sphere);
}

static t_plane	*set_plane(t_parse *parsed_objects)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	plane->kd = get_double(parsed_objects->KD, 0, 1);
	plane->ks = get_double(parsed_objects->KS, 0, 1);
	plane->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (plane);
}

static t_cylinder	*set_cylinder(t_parse *parsed_objects)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->center = get_double_vector(parsed_objects->point, 0, 0);
	cylinder->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(parsed_objects->height, 0, INFINITY);
	cylinder->kd = get_double(parsed_objects->KD, 0, 1);
	cylinder->ks = get_double(parsed_objects->KS, 0, 1);
	cylinder->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (cylinder);
}

void	*set_objects(t_scene **scene, t_objlst *object_list, void *mlx)
{
	t_parse		*parsed_object;
	t_objlst	*new_objects;

	parsed_object = object_list->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	new_objects->type = parsed_object->type;
	if (new_objects->type == SPHERE)
		new_objects->object = set_sphere(parsed_object);
	else if (new_objects->type == PLANE)
		new_objects->object = set_plane(parsed_object);
	else if (new_objects->type == CYLINDER)
		new_objects->object = set_cylinder(parsed_object);
	set_texture(new_objects, parsed_object, mlx);
	push_back(&(*scene)->objects, new_objects);
	return (scene);
}
