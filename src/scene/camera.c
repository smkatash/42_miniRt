/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:40 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/23 18:35:45 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"
#include <math.h>

static double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180);
}

static t_camera
	init_camera(t_screen *screen, t_point origin, t_vector direction, double h_fov)
{
	t_camera	camera;
	double		field_width;
	double		theta;

	theta = degree_to_radian(h_fov);
	field_width = tan(theta / 2) * 2.0;
	multiply_scalar(&camera.w_dir, &direction, -1);
	// Check coordinate
	coordinates_set(&camera.u_dir, &camera.v_dir, &camera.w_dir);
	camera.origin = origin;
	camera.viewport_width = field_width;
	camera.viewport_height = field_width * screen->aspect_ratio;
	multiply_scalar(&camera.horizontal, &camera.u_dir, camera.viewport_width);
	multiply_scalar(&camera.vertical, &camera.v_dir, camera.viewport_height);
	// LLB calculation
	addition(&camera.left_bottom, &camera.horizontal, &camera.vertical);
	divide_scalar(&camera.left_bottom, &camera.left_bottom, 2);
	addition(&camera.left_bottom,  &camera.left_bottom, &camera.w_dir);
	subtraction(&camera.left_bottom, &camera.origin, &camera.left_bottom);
	return (camera);
}

t_camera	set_camera(t_scene *scene, t_objlst *objects)
{
	t_parse		*parsed_list;
	t_camera	camera;
	t_point	    origin;
	t_vector	direction;
	double		h_fov;

	parsed_list = objects->object;
	origin = get_double_vector(parsed_list->point, 0, 0);
	direction = get_double_vector(parsed_list->nor_vec, -1, 1);
	h_fov = get_double(parsed_list->fov, 0, 180);
	camera = init_camera(&scene->screen, origin, direction, h_fov);
	return (camera);
}