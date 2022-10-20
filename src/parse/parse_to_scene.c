/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:54:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 23:40:51 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_scene	*parse_to_scene(t_scene *scene, t_objlst *object_list)
{
	t_parse		*object;

	scene = set_scene(WIN_WIDTH, WIN_HEIGHT);
	while (object_list)
	{
		object = object_list->object;
		if (object->type == AMBIENT)
			set_ambient(object_list);
		else if (object->type == CAMERA)
			set_camera(scene, object_list);
		else if (object->type == POINT_LIGHT)
			set_light(scene, object_list);
		else if (object->type == SPHERE)
			set_sphere(scene, object_list);
		else if (object->type == PLANE)
			set_plane(scene, object_list);
		else if (object->type == CYLINDER)
			set_cylinder(scene, object_list);
		object_list = object_list->next;
	}
	return (scene);
}