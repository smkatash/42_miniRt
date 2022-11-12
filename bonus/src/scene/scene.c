/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:59:46 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/11 21:14:23 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief defines parameters of screen
 * @return screen struct
 */
static t_screen	set_screen(int width, int height)
{
	t_screen	screen;

	screen.width = width;
	screen.height = height;
	screen.aspect_ratio = (double)height / (double)width;
	return (screen);
}

/**
 * @brief initializes scene
 * @return scene struct
 */
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
