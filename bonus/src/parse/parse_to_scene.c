/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:54:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/08 15:50:17 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*parse_to_scene(t_scene **scene, t_objlst *object_list, void *mlx)
{
	t_parse		*object;

	*scene = set_scene(WIN_WIDTH, WIN_HEIGHT);
	while (object_list)
	{
		object = object_list->object;
		if (object->type == AMBIENT)
			(*scene)->ambient = set_ambient(object_list);
		else if (object->type == CAMERA)
			(*scene)->camera = set_camera(*scene, object_list);
		else if (object->type == LIGHT)
			set_light(*scene, object_list);
		else if (object->type == SPHERE || object->type == PLANE || object->type == CYLINDER || object->type == CONE)
			set_objects(scene, object_list, mlx);
		object_list = object_list->next;
	}
	return (scene);
}
