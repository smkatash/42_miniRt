/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 23:21:37 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_hyperboloid_uv(t_record *p, t_hyper *hp)
{
	double		theta;
	double		h;
	t_vector	temp;

	coordinates_set(&p->u_dir, &p->v_dir, &hp->normal);
	subtraction(&temp, &p->point, &hp->center);
	theta = atan2(-1 * dot_product(&temp, &p->v_dir), dot_product(&temp, &p->u_dir)) + M_PI;
	h = dot_product(&temp, &hp->normal);
	p->u = theta * M_1_PI * 0.5;
	p->v = fmod_min(h);
}

static void	set_hit_record(t_record *record, t_hyper *hp)
{
	record->ks = hp->ks;
	record->kd = hp->kd;
	record->ksn = hp->ksn;
	record->objects = hp;
}

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_hyper		*hp;
	t_vector	temp;
	double		point;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	hp = (t_hyper *)objects->object;
	record->t = root;
	set_hit_record(record, hp);
	ray_at(&record->point, ray, root);
	subtraction(&temp, &record->point, &hp->center);
	point = dot_product(&temp, &hp->normal);
	if (point > hp->height || point < 0)
		return (false);
	point = hp->height - point;
	subtraction(&temp, &record->point, &hp->center);
	multiply_scalar(&record->normal, &hp->normal, dot_product(&temp, &hp->normal));
	addition(&record->normal, &record->normal, &hp->center);
	subtraction(&record->normal, &record->point, &record->normal);
	unit_vector(&record->normal, &record->normal);
	multiply_scalar(&record->normal, &record->normal, point);
	multiply_scalar(&temp, &hp->normal, hp->radius * point / hp->height);
	addition(&record->normal, &record->normal, &temp);
	unit_vector(&record->normal, &record->normal);
	set_face_normal(ray, record);
	set_hyperboloid_uv(record, hp);
	set_hit_texture(record, &objects->texture);
	return (true);
}

static void	*intersection(t_equation *eq, t_objlst *objects, t_ray *ray)
{
	t_hyper		*hp;
	t_vector	oc;
	double		k;
	// double		dir_norm;
	// double		dir_oc;

	hp = (t_hyper *)objects->object;
	k = hp->radius2 / (hp->height * hp->height);
	subtraction(&oc, &ray->origin, &hp->center);
	
	// dir_norm = dot_product(&ray->direction, &hp->normal);
	// dir_oc = dot_product(&ray->direction, &oc);
	// eq->a = length_sqrd(&ray->direction) - (1 + k) * (dir_norm * dir_norm);
	// eq->half_b = dir_oc - (1 + k) * dot_product(&oc, &hp->normal) * dir_norm + k * hp->height * dir_norm;
	// eq->c = length_sqrd(&oc) - (1 + k) * dot_product(&oc, &hp->normal) * dot_product(&oc, &hp->normal) \
	// 	 - hp->radius2 + 2 * k * hp->height * dot_product(&oc, &hp->normal);
	eq->a = dot_product(&ray->direction, &hp->normal) * dot_product(&ray->direction, &hp->normal) - k;
	eq->half_b = (dot_product(&ray->direction, &hp->normal)) * (dot_product(&oc, &hp->normal)) - dot_product(&ray->direction, &oc) * k;
	eq->c = dot_product(&oc, &hp->normal) * dot_product(&oc, &hp->normal) - dot_product(&oc, &oc) * k;
	return (eq);
}

bool	hit_hyperboloid(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_equation	eq;

	intersection(&eq, objects, ray);
	if (hit_point(objects, ray, record, nearest_root(&eq, 0)))
		return (true);
	if (hit_point(objects, ray, record, nearest_root(&eq, 1)))
		return (true);
	return (false);
}