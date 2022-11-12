/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:03:06 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/12 11:56:39 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief registers hit point and updates record normal
 */
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
	record->color = objects->color;
	return (true);
}

/**
 * @brief cylinder-ray hit equation
 * @cite |(𝐱(𝑡)−𝐱1)×(𝐱(𝑡)−𝐱2)|2 / |𝐱1−𝐱2|2 =𝑟2.
 */
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

/**
 * @brief cylinder-ray intersection and hit vefification
 */
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
