/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:25:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/02 12:53:09 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

double	fmod_dot(t_vector *v, t_vector *u)
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
void	set_plane_uv(t_record *p)
{
	coordinates_set(&p->u_dir, &p->v_dir, p->normal);
	record->v = fmod_dot(&p->point, &p->v_dir);
	record->u = fmod_dot(&p->point, &p->u_dir);
}

// t = -(p-a).N / v.N
// (ray origin  - point on the plane).Nplane divided by
// ray direction . Nplane
bool	hit_plane(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_plane		*plane;
	double		denominator;
	double		num;
	t_vector	temp;
	double		root;

	plane = (t_plane *)objects->object;
	denominator = dot_product(&ray->direction, &plane->normal);
	if (denominator == 0)
		return (false);
	subtraction(&temp, &ray->origin, &plane->point);
	num = dot_product(&temp, &plane->normal) * -1;
	root = num / denominator;
	if (root > record->tmax || root < record->tmin)
		return (false);
	record->t = root;
	record->objects = plane;
	ray_at(&record->point, ray, root);
	record->normal = plane->normal;
	set_face_normal(ray, record);
	set_plane_uv(record);
	set_hit_texture(record, objects);
	return (true);
}
