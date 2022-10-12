/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:59:46 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:06:46 by kanykei          ###   ########.fr       */
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
	t_scene		*scene;

	scene = ft_calloc(sizeof(t_scene), 0);
	scene->screen = set_screen(width, height);
	return (scene);
}