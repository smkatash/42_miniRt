/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:54:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:22:04 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_scene	*parse_to_scene(t_scene *scene, t_objlst *object_list)
{
	t_parse		*object;

	scene = set_scene(WIN_WIDTH, WIN_HEIGHT);
	while (object_list)
	{
		object = object_list->object;
		if (object->type == AMBIENT)
			scene->ambient = ambient_set(object_list);
		else if (object->type == CAMERA)
			scene->camera = camera_set(scene, object_list);
		else if (object->type == POINT_LIGHT)
			light_set(scene, object_list);
		else if (object->type == SPHERE)
			sphere_set(scene, object_list);
		else if (object->type == PLANE)
			plane_set(scene, object_list);
		else if (object->type == CYLINDER)
			cylinder_set(scene, object_list);
		object_list = object_list->next;
	}
	return (scene);
}