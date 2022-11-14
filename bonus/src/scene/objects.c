/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 11:42:02 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief sets sphere parameters
 * @return sphere
 */
static t_sphere	*set_sphere(t_parse *parsed_objects)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		error_message("Malloc error\n");
	sphere->center = get_double_vector(parsed_objects->point, 0, 0);
	sphere->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	sphere->kd = get_double(parsed_objects->kd, 0, 1);
	sphere->ks = get_double(parsed_objects->ks, 0, 1);
	sphere->ksn = get_double(parsed_objects->ksn, 0, INFINITY);
	return (sphere);
}

/**
 * @brief sets plane parameters
 * @return plane
 */
static t_plane	*set_plane(t_parse *parsed_objects)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_message("Malloc error\n");
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	plane->radius = INFINITY;
	plane->kd = get_double(parsed_objects->kd, 0, 1);
	plane->ks = get_double(parsed_objects->ks, 0, 1);
	plane->ksn = get_double(parsed_objects->ksn, 0, INFINITY);
	return (plane);
}

/**
 * @brief sets cone parameters
 * @return cone
 */
static t_cone	*set_cone(t_parse *parsed_objects)
{
	t_cone	*cone;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		error_message("Malloc error\n");
	cone->center = get_double_vector(parsed_objects->point, 0, 0);
	cone->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cone->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cone->radius2 = cone->radius * cone->radius;
	cone->height = get_double(parsed_objects->height, 0, INFINITY);
	cone->kd = get_double(parsed_objects->kd, 0, 1);
	cone->ks = get_double(parsed_objects->ks, 0, 1);
	cone->ksn = get_double(parsed_objects->ksn, 0, INFINITY);
	return (cone);
}

/**
 * @brief sets cylinder parameters
 * @return cylinder
 */
static t_cylinder	*set_cylinder(t_parse *parsed_objects)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_message("Malloc error\n");
	cylinder->center = get_double_vector(parsed_objects->point, 0, 0);
	cylinder->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(parsed_objects->height, 0, INFINITY);
	cylinder->kd = get_double(parsed_objects->kd, 0, 1);
	cylinder->ks = get_double(parsed_objects->ks, 0, 1);
	cylinder->ksn = get_double(parsed_objects->ksn, 0, INFINITY);
	return (cylinder);
}

/**
 * @brief sets object parameters according to object types
 * @return scene with objects
 */
void	*set_objects(t_scene **scene, t_objlst *object_list, void *mlx)
{
	t_parse		*parsed_object;
	t_objlst	*new_objects;

	parsed_object = object_list->object;
	new_objects = ft_calloc(1, sizeof(t_objlst));
	if (!new_objects)
		error_message("Malloc error\n");
	new_objects->type = parsed_object->type;
	push_back(&(*scene)->objects, new_objects);
	if (new_objects->type == SPHERE)
		new_objects->object = set_sphere(parsed_object);
	else if (new_objects->type == PLANE)
		new_objects->object = set_plane(parsed_object);
	else if (new_objects->type == CONE)
		new_objects->object = set_cone(parsed_object);
	else if (new_objects->type == CYLINDER)
	{
		new_objects->object = set_cylinder(parsed_object);
		set_cylinder_caps(scene, new_objects->object, parsed_object, mlx);
	}
	set_texture(new_objects, parsed_object, mlx);
	return (scene);
}
