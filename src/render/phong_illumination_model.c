/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_illumination_model.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/24 15:21:21 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

bool    overcast_shadow(t_scene *scene, t_vector *light_dir, double t)
{
    t_ray			shadow;
	t_record	    shadow_hit;

	shadow.direction = *light_dir;
    multiply_scalar(&shadow.origin, light_dir, EPSILON);
    addition(&shadow.origin, &shadow.origin, &scene->record.point);
    // printf("sh %f %f %f\n", shadow.direction.x, shadow.direction.y, shadow.direction.z);
    // printf("sh %f %f %f\n", shadow.origin.x, shadow.origin.y, shadow.origin.z);
    shadow_hit.tmin = 0;
	shadow_hit.tmax = t;
	if (hit(scene->objects, &shadow, &shadow_hit))
		return (true);
	return (false);
}

// diffuse = Kd * (N dot L)
// Kd is the diffuse reflection constant

void    *lambertian_diffuse(t_scene *scene, t_objlst *lights, t_vector *light_dir, t_color *diff_comp)
{
    double  Kd;

    Kd = fmax(0, dot_product(light_dir, &scene->record.normal));
    multiply_scalar(diff_comp, &lights->color, Kd);
    return (diff_comp);
}

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
void    *phong_specular(t_scene *scene, t_objlst *lights, t_vector *light_dir, t_color *spec_com)
{
    t_vector        V;
    t_vector        R;
    const double    Ks = 0.1;
    const double    n = 50;
    double          specular;
    
    multiply_scalar(&V, &scene->ray.direction, -1);
    unit_vector(&V, &V);
    reflect(&R, light_dir, &scene->record.normal);
    specular = pow(fmax(0, dot_product(&R, &V)), n);
    multiply_scalar(spec_com, &lights->color, Ks);
    multiply_scalar(spec_com, spec_com, specular);
    return (spec_com);
}
