/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:40 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:15:01 by kanykei          ###   ########.fr       */
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
	camera.w_dir = vec3_mult_scalar(direction, -1);
	coordinate_system(&camera.u_dir, &camera.v_dir, camera.w_dir);
	camera.origin = origin;
	camera.viewport_width = field_width;
	camera.viewport_height = field_width * screen->aspect_ratio;
	camera.horizontal = vec3_mult_scalar(camera.u_dir, camera.viewport_width);
	camera.vertical = vec3_mult_scalar(camera.v_dir, camera.viewport_height);
	camera.left_bottom = vec3_minus(camera.origin, vec3_plus(
				vec3_divide_scalar(vec3_plus(camera.horizontal, camera.vertical), 2),
				camera.w_dir));
	return (camera);
}

t_camera	set_camera(t_scene *scene, t_objlist *objects)
{
	t_parse		*parsed_list;
	t_camera	camera;
	t_point	    origin;
	t_vector	direction;
	double		h_fov;

	parsed_list = objects->object;
	origin = vec_double_get(parsed_list->point, 0, 0);
	direction = vec_double_get(parsed_list->nor_vec, -1, 1);
	h_fov = double_get(parsed_list->fov, 0, 180);
	camera = init_camera(&scene->screen, origin, direction, h_fov);
	return (camera);
}