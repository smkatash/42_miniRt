/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:43:52 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/11 02:14:32 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_plane	*cylinder_plane(t_cylinder *cy, t_point	center)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_message("Malloc error\n");
	plane->point = center;
	plane->normal = cy->normal;
	plane->radius = cy->radius;
	plane->kd = cy->kd;
	plane->ks = cy->ks;
	plane->ksn = cy->ksn;
	return (plane);
}

static void	set_cylinder_top(t_scene **scene, t_cylinder *cy, \
	t_parse *parsed_object, void *mlx)
{
	t_objlst	*new_object;
	t_plane		*top_cap;

	new_object = malloc(sizeof(t_objlst));
	if (!new_object)
		error_message("Malloc error\n");
	push_back(&(*scene)->objects, new_object);
	top_cap = cylinder_plane(cy, cy->center);
	new_object->object = top_cap;
	new_object->type = PLANE;
	set_texture(new_object, parsed_object, mlx);
}

static void	set_cylinder_btm(t_scene **scene, t_cylinder *cy, \
	t_parse *parsed_object, void *mlx)
{
	t_objlst	*new_object;
	t_vector	temp;
	t_plane		*btm_cap;

	new_object = malloc(sizeof(t_objlst));
	if (!new_object)
		error_message("Malloc error\n");
	push_back(&(*scene)->objects, new_object);
	multiply_scalar(&temp, &cy->normal, cy->height);
	addition(&temp, &temp, &cy->center);
	btm_cap = cylinder_plane(cy, temp);
	new_object->object = btm_cap;
	new_object->type = PLANE;
	set_texture(new_object, parsed_object, mlx);
}

void	set_cylinder_caps(t_scene **scene, t_cylinder *cy, \
	t_parse *parsed_object, void *mlx)
{
	set_cylinder_top(scene, cy, parsed_object, mlx);
	set_cylinder_btm(scene, cy, parsed_object, mlx);
}
