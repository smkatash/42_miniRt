/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:09:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/25 10:23:44 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	*set_light(t_scene *scene, t_objlst *objects)
{
	t_objlst	*new_objects;
	t_parse		*parsed_objects;
	t_light		*light;

	parsed_objects = objects->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	push_back(&scene->lights, new_objects);
	light->origin = get_double_vector(parsed_objects->point, 0, 0);
	light->bright_ratio = get_double(parsed_objects->bri_ratio, 0.0, 1.0);
	new_objects->type = LIGHT;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = light;
	return (scene);
}
