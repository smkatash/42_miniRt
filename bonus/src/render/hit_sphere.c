/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:26:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 13:15:59 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

// 𝑣 = 𝜃 / 𝜋
// 𝜃=acos(−𝑦)
// 𝑢 = 𝜙 / 2𝜋
// 𝜙= atan2(−𝑧,𝑥)+𝜋
void	set_sphere_uv(t_record *p)
{
	double	theta;
	double	phi;

	coordinates_set(&p->u_dir, &p->v_dir, &p->normal);
	theta = acos(-1 * p->normal.y);
	p->v = theta / M_PI;
	phi = atan2(-1 * p->normal.z, p->normal.x) + M_PI;
	p->u = phi / (2 * M_PI);
}

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_sphere	*sphere;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	sphere = objects->object;
	record->objects = sphere;
	record->t = root;
	record->ks = sphere->ks;
	record->kd = sphere->kd;
	record->ksn = sphere->ksn;
	ray_at(&record->point, ray, root);
	unit_vector(&record->normal, subtraction(&record->normal, &record->point,
			&sphere->center));
	set_face_normal(ray, record);
	set_sphere_uv(record);
	set_hit_texture(record, &objects->texture);
	return (true);
}

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
// 𝑡2𝐛⋅𝐛+2𝑡𝐛⋅(𝐀−𝐂)+(𝐀−𝐂)⋅(𝐀−𝐂)−𝑟2=0
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
