/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/08 16:35:59 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_cone_uv(t_record *p, t_cone *cone)
{
	double		theta;
	double		h;
	t_vector	temp;

	coordinates_set(&p->u_dir, &p->v_dir, &cone->normal);
	subtraction(&temp, &p->point, &cone->center);
	theta = atan2(-1 * dot_product(&temp, &p->v_dir), dot_product(&temp, &p->u_dir)) + M_PI;
	h = dot_product(&temp, &cone->normal);
	p->u = theta * M_PI / 2 * 0.5;
	p->v = fmod_min(h);
}

static void	set_hit_record(t_record *record, t_cone *cone)
{
	record->ks = cone->ks;
	record->kd = cone->kd;
	record->ksn = cone->ksn;
	record->objects = cone;
}

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_cone		*cone;
	t_vector	temp;
	double		point;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	cone = (t_cone *)objects->object;
	record->t = root;
	set_hit_record(record, cone);
	ray_at(&record->point, ray, root);
	subtraction(&temp, &record->point, &cone->center);
	point = dot_product(&temp, &cone->normal);
	if (point > cone->height || point < 0)
		return (false);
	point = cone->height - point;
	subtraction(&temp, &record->point, &cone->center);
	multiply_scalar(&record->normal, &cone->normal, dot_product(&temp, &cone->normal));
	addition(&record->normal, &record->normal, &cone->center);
	subtraction(&record->normal, &record->point, &record->normal);
	unit_vector(&record->normal, &record->normal);
	multiply_scalar(&record->normal, &record->normal, point);
	multiply_scalar(&temp, &cone->normal, (cone->radius * point / cone->height));
	addition(&record->normal, &record->normal, &temp);
	unit_vector(&record->normal, &record->normal);
	set_face_normal(ray, record);
	set_cone_uv(record, cone);
	set_hit_texture(record, &objects->texture);
	return (true);
}

static void	*intersection(t_equation *eq, t_objlst *objects, t_ray *ray)
{
	t_cone		*cone;
	t_vector	oc;
	double		k;
	double		dir_norm;
	double		dir_oc;

	cone = (t_cone *)objects->object;
	k = cone->radius2 / (cone->height * cone->height);
	subtraction(&oc, &ray->origin, &cone->center);
	dir_norm = dot_product(&ray->direction, &cone->normal);
	dir_oc = dot_product(&ray->direction, &oc);
	eq->a = length_sqrd(&ray->direction) - (1 + k) * (dir_norm * dir_norm);
	eq->half_b = dir_oc - (1 + k) * dot_product(&oc, &cone->normal) * dir_norm + k * cone->height * dir_norm;
	eq->c = length_sqrd(&oc) - (1 + k) * dot_product(&oc, &cone->normal) * dot_product(&oc, &cone->normal) \
		 - cone->radius2 + 2 * k * cone->height * dot_product(&oc, &cone->normal);
	return (eq);
}

bool	hit_cone(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_equation	eq;

	intersection(&eq, objects, ray);
	if (hit_point(objects, ray, record, nearest_root(&eq, 0)))
		return (true);
	if (hit_point(objects, ray, record, nearest_root(&eq, 1)))
		return (true);
	return (false);
}