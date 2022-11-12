/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:25:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 15:26:50 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief computes the floating-point remainder of the division operation
 * for vectors
 */
static double	fmod_dot(t_vector *v, t_vector *u)
{
	double	t;

	t = fmod(dot_product(v, u), 1);
	if (t < 0)
		return (t + 1);
	return (t);
}

/**
 * @brief planar UV mapping
 * @cite 
 * u ← p.x mod 1
 * v ← p.z mod 1
 */
static void	set_plane_uv(t_record *p)
{
	coordinates_set(&p->u_dir, &p->v_dir, &p->normal);
	p->v = fmod_dot(&p->point, &p->v_dir);
	p->u = fmod_dot(&p->point, &p->u_dir);
}

/**
 * @brief gets plane parameters into record
 */
static void	set_hit_record(t_record *record, t_plane *plane)
{
	record->objects = plane;
	record->ks = plane->ks;
	record->kd = plane->kd;
	record->ksn = plane->ksn;
	record->normal = plane->normal;
}

/**
 * @brief checks plane to radius of a cylinder
 */
static bool	cylinder_plane(t_record *record, t_plane *plane)
{
	t_vector	temp;

	if (plane->radius != INFINITY)
	{
		subtraction(&temp, &plane->point, &record->point);
		if (length(&temp) > plane->radius)
			return (false);
	}
	return (true);
}

/**
 * @brief plane-ray intersection
 * @cite l∗t⋅n+(l0−po)⋅n=0
 * (p−p0)⋅n=0
 * l0+l∗t=p
 * t = -(p-a).N / v.N
 * (ray origin  - point on the plane).Nplane divided by
 * ray direction . Nplane
 */
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
	if (cylinder_plane(record, plane) == false)
		return (false);
	set_hit_record(record, plane);
	set_face_normal(ray, record);
	set_plane_uv(record);
	set_hit_texture(record, &objects->texture);
	return (true);
}
