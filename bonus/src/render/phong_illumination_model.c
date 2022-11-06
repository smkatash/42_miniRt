/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_illumination_model.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 14:02:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

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

// diffuse = kd * (N dot L)
// kd is the diffuse reflection constant
void	*lambertian_diffuse(t_scene *scene, t_objlst *lights,
						t_vector *light_dir, t_color *diff_comp)
{
	double	component;

	component = fmax(0, dot_product(light_dir, &scene->record.normal)) * scene->record.kd;
	multiply_scalar(diff_comp, &lights->texture.color, component);
	return (diff_comp);
}

// R = 2(N⋅L)N−L.
static void	*reflect(t_vector *R, t_vector *L, t_vector *N)
{
	multiply_scalar(R, N, 2 * dot_product(N, L));
	subtraction(R, R, L);
	return (R);
}

// specular = Ks * (R dot V)^n
// R = 2(N⋅L)N−L.
// Ks is the specular component
// The larger the exponential power (n) the smaller and more
// intense the specular intensity bump. Hence specular highlights.
void	*phong_specular(t_scene *scene, t_objlst *lights, t_vector *light_dir,
						t_color *spec_com)
{
	t_vector		v;
	t_vector		r;
	double			ks;
	double			n;
	double			specular;

	ks = scene->record.ks;
	n = scene->record.ksn;
	multiply_scalar(&v, &scene->ray.direction, -1);
	unit_vector(&v, &v);
	reflect(&r, light_dir, &scene->record.normal);
	specular = pow(fmax(0, dot_product(&r, &v)), n);
	multiply_scalar(spec_com, &lights->texture.color, ks);
	multiply_scalar(spec_com, spec_com, specular);
	return (spec_com);
}