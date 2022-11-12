/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:26:28 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 12:34:42 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @cite  
 * N = surface normal
 *  L = unit vector between point and light
 * V = unit vector between point and view
 * R = light reflection unit vector (mirror of L about N)
 * Labertian diffuse = Kd * (N dot L)
 * Phong spectral reflectivity: diffuse + Ks * (R dot V)^n
 * Phong lighting equation:
 * Kd * (N dot L) + Ks * (R dot V)^n
 */

/**
 * @brief colors local illumination of points on a surface
 * @cite SP=diffuse()∗ Kd + specular()∗Ks.
 */
static void	*point_and_light(t_scene *scene, t_objlst *lights, t_color *illum)
{
	t_light		*lightning;
	t_vector	dir;
	double		t;
	t_color		diffuse;
	t_color		specular;

	lightning = (t_light *)lights->object;
	subtraction(&dir, &lightning->origin, &scene->record.point);
	t = length(&dir);
	unit_vector(&dir, &dir);
	if (overcast_shadow(scene, &dir, t))
		return (illum = &(t_color){0, 0, 0});
	lambertian_diffuse(scene, lights, &dir, &diffuse);
	phong_specular(scene, lights, &dir, &specular);
	addition(illum, &diffuse, &specular);
	multiply_scalar(illum, illum, lightning->bright_ratio);
	return (illum);
}

/**
 * @brief sets local illumination of points on a surface
 * @cite SP=diffuse()∗ Kd + specular()∗Ks.
 */
void	*phong_model(t_scene *scene, t_color *pxl)
{
	t_objlst	*lights;
	t_color		ambient;

	lights = scene->lights;
	while (lights)
	{
		if (lights->type == LIGHT)
		{
			point_and_light(scene, lights, pxl);
			addition(pxl, pxl, &(t_color){0, 0, 0});
		}
		lights = lights->next;
	}
	multiply_scalar(&ambient, &scene->ambient.light_color,
		scene->ambient.light_ratio);
	addition(pxl, pxl, &ambient);
	multiply(pxl, pxl, &scene->record.color);
	minimum(pxl, pxl, &(t_color){1, 1, 1});
	return (pxl);
}
