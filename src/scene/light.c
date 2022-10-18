/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:09:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 02:12:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

void	light_set(t_scene *scene, t_objlst *objects)
{
	t_objlist	*new_objects;
	t_parse		*parsed_objects;
	t_light		*light;

	parsed_objects = objects->object;
	new_objects = ft_calloc(sizeof(t_objlist), 0);
	light = ft_calloc(sizeof(t_light), 0);
	push_back(&scene->lights, new_objects);
	light->origin = get_double_vector(parsed_objects->point, 0, 0);
	light->bright_ratio = get_double(parsed_objects->bri_ratio, 0.0, 1.0);
	new_objects->type = POINT_LIGHT;
	new_objects->color = get_int_vector(parsed_objects->rgb, 0, 255);
	new_objects->object = light;
}