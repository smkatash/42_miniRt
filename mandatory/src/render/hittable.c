/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:22:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 02:46:35 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief solve quadratc equation
 * @cite x =  −b +/- √(b2 − 4ac) / 2a
 * Infinite roots/1 root/2 roots
 */
double	nearest_root(t_equation *eq, int range)
{
	double	discriminant;
	double	sqrtd;
	double	root;

	discriminant = eq->half_b * eq->half_b - eq->a * eq->c;
	if (discriminant < 0)
		return (NAN);
	sqrtd = sqrt(discriminant);
	if (range == 0)
		root = (eq->half_b * (-1) - sqrtd) / eq->a;
	else if (range == 1)
		root = (eq->half_b * (-1) + sqrtd) / eq->a;
	else
		root = NAN;
	return (root);
}

/**
 * @brief sets the normal to outward of surface
 * @cite if the ray is outside, the normal will point outward, 
 * otherwise the normal will point inward.
 */
void	set_face_normal(t_ray *ray, t_record *record)
{
	record->front_face = dot_product(&ray->direction, &record->normal) < 0;
	if (record->front_face == false)
		multiply_scalar(&record->normal, &record->normal, -1);
}

/**
 * @brief defines hit object type
 * @return true/false of a hit
 */
static void	*hit_object_type(t_objlst object)
{
	if (object.type == SPHERE)
		return (hit_sphere);
	if (object.type == PLANE)
		return (hit_plane);
	if (object.type == CYLINDER)
		return (hit_cylinder);
	return (false);
}

/**
 * @brief sets hit to true/false
 * @return true/false of a hit
 */
static bool	hit_object(t_objlst *objects, t_ray *ray, t_record *record)
{
	bool				hit_;
	const t_hittable	hit_object = hit_object_type(*objects);

	hit_ = false | hit_object(objects, ray, record);
	return (hit_);
}

/**
 * @brief records object hits with parameter
 * @return true/false of a hit
 */
bool	hit(t_objlst *objects, t_ray *ray, t_record *record)
{
	bool		hit_;
	t_record	temp;

	hit_ = false;
	temp = *record;
	while (objects)
	{
		if (hit_object(objects, ray, &temp))
		{
			hit_ = true;
			temp.tmax = temp.t;
			*record = temp;
		}
		objects = objects->next;
	}
	return (hit_);
}
