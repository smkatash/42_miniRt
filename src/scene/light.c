/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:09:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:12:21 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	light_set(t_scene *scene, t_objlist *objects)
{
	t_objlist	*new_objects;
	t_parse		*parsed_objects;
	t_light		*light;

	parsed_objects = objects->object;
	new_objects = ft_calloc(sizeof(t_objlist), 0);
	light = ft_calloc(sizeof(t_light), 0);
	add_object_list(&scene->lights, new_objects);
	light->origin = vec_double_get(parsed_objects->point, 0, 0);
	light->bright_ratio = double_get(parsed_objects->bri_ratio, 0.0, 1.0);
	new_objects->type = POINT_LIGHT;
	new_objects->color = vec_int_get(parsed_objects->rgb, 0, 255);
	new_objects->object = light;
}