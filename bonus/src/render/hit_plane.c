/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:25:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/10 23:16:41 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	fmod_min(double t)
{
	t = fmod(t, 1);
	if (t < 0)
		return (t + 1);
	return (t);
}

static double	fmod_dot(t_vector *v, t_vector *u)
{
	double	t;

	t = fmod(dot_product(v, u), 1);
	if (t < 0)
		return (t + 1);
	return (t);
}

// function planar_map(p)
//   u ← p.x mod 1
//  v ← p.z mod 1
static void	set_plane_uv(t_record *p)
{
	coordinates_set(&p->u_dir, &p->v_dir, &p->normal);
	p->v = fmod_dot(&p->point, &p->v_dir);
	p->u = fmod_dot(&p->point, &p->u_dir);
}

static void	set_hit_record(t_record *record, t_plane *plane)
{
	record->objects = plane;
	record->ks = plane->ks;
	record->kd = plane->kd;
	record->ksn = plane->ksn;
	record->normal = plane->normal;
}

// t = -(p-a).N / v.N
// (ray origin  - point on the plane).Nplane divided by
// ray direction . Nplane
bool	hit_plane(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_plane		*plane;
	double		denominator;
	t_vector	temp;
	double		root;

	plane = (t_plane *)objects->object;
	denominator = dot_product(&ray->direction, &plane->normal);
	if (denominator == 0)
		return (false);
	subtraction(&temp, &plane->point, &ray->origin);
	root = dot_product(&temp, &plane->normal) / denominator;
	if (root > record->tmax || root < record->tmin)
		return (false);
	record->t = root;
	ray_at(&record->point, ray, root);
	if (plane->radius != INFINITY)
	{
		subtraction(&temp, &plane->point, &record->point);
		if (length(&temp) > plane->radius)
			return (false);
	}
	set_hit_record(record, plane);
	set_face_normal(ray, record);
	set_plane_uv(record);
	set_hit_texture(record, &objects->texture);
	return (true);
}
