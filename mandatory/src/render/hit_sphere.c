/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:26:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/08 19:41:52 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_sphere	*sphere;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	sphere = (t_sphere *)objects->object;
	record->t = root;
	ray_at(&record->point, ray, root);
	unit_vector(&record->normal, subtraction(&record->normal, &record->point,
			&sphere->center));
	set_face_normal(ray, record);
	record->color = objects->color;
	return (true);
}

// 𝑡2𝐛⋅𝐛+2𝑡𝐛⋅(𝐀−𝐂)+(𝐀−𝐂)⋅(𝐀−𝐂)−𝑟2=0
static void	*intersection(t_equation *eq, t_objlst *objects, t_ray *ray)
{
	t_sphere	*sphere;
	t_vector	oc;

	sphere = (t_sphere *)objects->object;
	subtraction(&oc, &ray->origin, &sphere->center);
	eq->a = length_sqrd(&ray->direction);
	eq->half_b = dot_product(&ray->direction, &oc);
	eq->c = length_sqrd(&oc) - sphere->radius2;
	return (eq);
}

// 𝐏(𝑡)=𝐀+𝑡𝐛
bool	hit_sphere(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_equation	eq;

	intersection(&eq, objects, ray);
	if (hit_point(objects, ray, record, nearest_root(&eq, 0)))
		return (true);
	if (hit_point(objects, ray, record, nearest_root(&eq, 1)))
		return (true);
	return (false);
}
