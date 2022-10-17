/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:15:38 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/17 15:04:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_ambient	set_ambient(t_objlst *objects)
{
	t_parse		*parsed_list;
	t_ambient	ambient;

	parsed_list = objects->object;
	ambient.light_ratio = double_get(parsed_list->bri_ratio, 0.0, 1.0);
	ambient.light_color = vec_int_get(parsed_list->rgb, 0, 255);
	return (ambient);
}
