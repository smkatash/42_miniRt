/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:20:28 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/12 12:21:48 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_scene	*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if(!scene)
		error_exit(-1);
	scene->cams = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->hight = 0;
	return(scene);
}
