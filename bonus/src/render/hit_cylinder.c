/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:48:40 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/31 18:50:59 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

double	fmod_min(double t)
{
	t = fmod(t, 1);
	if (t < 0)
		return (t + 1);
	return (t);
}
// compute the azimuthal angle, same as with spherical_map()
// theta ← arctan2(p.x, p.z)
// raw_u ← theta / (2 * π)
// u ← 1 - (raw_u + 0.5)

//  v go from 0 to 1 between whole units of y
// v ← p.y mod 1
void	set_cylinder_uv(t_record *p, t_cylinder* cylinder)
{
	double		theta;
	t_vector	temp;

	coordinates_set(&p->u_dir, &p->v_dir, cylinder->normal);
	subtraction(&temp, &record->point, &cylinder->center);
	theta = atan2(&record->normal.z, record->normal.x)
	record->u = 1 - (theta / (2 * M_PI) + 0.5);
	record->v = fmod_min(&p->point.y, 1);
}

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_cylinder	*cylinder;
	t_vector	temp;
	double		point;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	cylinder = (t_cylinder *)objects->object;
	record->t = root;
	record->objects = cylinder;
	ray_at(&record->point, ray, root);
	subtraction(&temp, &record->point, &cylinder->center);
	point = dot_product(&temp, &cylinder->normal);
	if (point > cylinder->height || point < 0)
		return (false);
	subtraction(&record->normal, &record->point, &cylinder->center);
	multiply_scalar(&record->normal, &record->normal,
		dot_product(&record->normal, &cylinder->normal));
	addition(&record->normal, &record->normal, &cylinder->center);
	subtraction(&record->normal, &record->point, &record->normal);
	unit_vector(&record->normal, &record->normal);
	set_face_normal(ray, record);
	set_face_normal(ray, record);
	set_cylinder_uv(record, cylinder);
	set_hit_texture(record, objects);
	return (true);
}

static void	*intersection(t_equation *eq, t_objlst *objects, t_ray *ray)
{
	t_cylinder	*cylinder;
	t_vector	oc;
	double		dot_ray_cy;
	double		dot_oc_cy;

	cylinder = (t_cylinder *)objects->object;
	subtraction(&oc, &ray->origin, &cylinder->center);
	dot_ray_cy = dot_product(&ray->direction, &cylinder->normal);
	dot_oc_cy = dot_product(&oc, &cylinder->normal);
	eq->a = length_sqrd(&ray->direction) - (dot_ray_cy * dot_ray_cy);
	eq->half_b = dot_product(&ray->direction, &oc) - (dot_ray_cy * dot_oc_cy);
	eq->c = length_sqrd(&oc) - cylinder->radius2 - (dot_oc_cy * dot_oc_cy);
	return (eq);
}

bool	hit_cylinder(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_equation	eq;

	intersection(&eq, objects, ray);
	if (hit_point(objects, ray, record, nearest_root(&eq, 0)))
		return (true);
	if (hit_point(objects, ray, record, nearest_root(&eq, 1)))
		return (true);
	return (false);
}
