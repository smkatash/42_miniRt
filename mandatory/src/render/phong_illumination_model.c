/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_illumination_model.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 03:55:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief checks if shadow hits object
 * @return true/false
 */
bool	overcast_shadow(t_scene *scene, t_vector *light_dir, double t)
{
	t_ray		shadow;
	t_record	shadow_hit;

	shadow.direction = *light_dir;
	multiply_scalar(&shadow.origin, light_dir, EPSILON);
	addition(&shadow.origin, &shadow.origin, &scene->record.point);
	shadow_hit.tmin = 0;
	shadow_hit.tmax = t;
	if (hit(scene->objects, &shadow, &shadow_hit))
		return (true);
	return (false);
}

/**
 * @brief calculates diffuse component
 * @cite diffuse = kd * (N dot L)
 */
void	*lambertian_diffuse(t_scene *scene, t_objlst *lights,
						t_vector *light_dir, t_color *diff_comp)
{
	double	kd;

	kd = fmax(0, dot_product(light_dir, &scene->record.normal));
	multiply_scalar(diff_comp, &lights->color, kd);
	return (diff_comp);
}

/**
 * @brief calculates reflectance component
 * @cite R = 2(N⋅L)N−L.
 */
static void	*reflect(t_vector *R, t_vector *L, t_vector *N)
{
	multiply_scalar(R, N, 2 * dot_product(N, L));
	subtraction(R, R, L);
	return (R);
}

/**
 * @brief calculates specular component
 * @cite specular = Ks * (R dot V)^n
 */
void	*phong_specular(t_scene *scene, t_objlst *lights, t_vector *light_dir,
						t_color *spec_com)
{
	t_vector		v;
	t_vector		r;
	const double	ks = 0.1;
	const double	n = 50;
	double			specular;

	multiply_scalar(&v, &scene->ray.direction, -1);
	unit_vector(&v, &v);
	reflect(&r, light_dir, &scene->record.normal);
	specular = pow(fmax(0, dot_product(&r, &v)), n);
	multiply_scalar(spec_com, &lights->color, ks);
	multiply_scalar(spec_com, spec_com, specular);
	return (spec_com);
}
