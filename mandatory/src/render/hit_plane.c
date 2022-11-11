/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:25:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/10 16:41:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//     float denom = dotProduct(n, l); 
//     if (denom > 1e-6) { 
//         Vec3f p0l0 = p0 - l0; 
//         t = dotProduct(p0l0, n) / denom; 
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
	record->normal = plane->normal;
	set_face_normal(ray, record);
	record->color = objects->color;
	return (true);
}
