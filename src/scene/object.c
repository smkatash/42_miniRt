/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:09:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	set_sphere(t_scene *scene, t_objlist *objects)
{
	t_objlist	*new_objects;
	t_parse		*parsed_objects;
	t_sphere	*sphere;

	parsed_objects = objects->object;
	new_objects = ft_calloc(sizeof(t_objlist), 0);
	sphere = ft_calloc(sizeof(t_sphere), 0);
	add_object_list(&scene->objects, new_objects);
	sphere->center = vec_double_get(parsed_objects->point, 0, 0);
	sphere->radius = double_get(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	new_objects->type = SPHERE;
	new_objects->color = vec_int_get(parsed_objects->rgb, 0, 255);
	new_objects->object = sphere;
}

void	set_plane(t_scene *scene, t_objlist *objects)
{
	t_objlist	*new_objects;
	t_parse		*parsed_objects;
	t_plane		*plane;

	parsed_objects = objects->object;
	new_objects = ft_calloc(sizeof(t_objlist), 0);
	plane = ft_calloc(sizeof(t_plane), 0);
	add_object_list(&scene->objects, new_objects);
	plane->point = vec_double_get(parsed_objects->point, 0, 0);
	plane->normal = vec_double_get(parsed_objects->nor_vec, -1, 1);
	new_objects->type = PLANE;
	new_objects->color = vec_int_get(parsed_objects->rgb, 0, 255);
	new_objects->object = plane;
}

void	set_cylinder(t_scene *scene, t_objlist *objects)
{
	t_objlist	*new_objects;
	t_parse		*parsed_objects;
	t_cylinder	*cylinder;

	parsed_objects = objects->object;
	new_objects = ft_calloc(sizeof(t_objlist), 0);
	cylinder = ft_calloc(sizeof(t_cylinder), 0);
	add_object_list(&scene->objects, new_objects);
	cylinder->center = vec_double_get(parsed_objects->point, 0, 0);
	cylinder->normal = vec_double_get(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = double_get(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = double_get(parsed_objects->height, 0, INFINITY);
	new_objects->type = CYLINDER;
	new_objects->color = vec_int_get(parsed_objects->rgb, 0, 255);
	new_objects->object = cylinder;
}