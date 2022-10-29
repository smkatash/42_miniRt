/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:59:46 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/25 10:18:36 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

static t_screen	set_screen(int width, int height)
{
	t_screen	screen;

	screen.width = width;
	screen.height = height;
	screen.aspect_ratio = (double)height / (double)width;
	return (screen);
}

t_scene	*set_scene(int width, int height)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->screen = set_screen(width, height);
	scene->objects = NULL;
	scene->lights = NULL;
	return (scene);
}
