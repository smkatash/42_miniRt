/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 19:40:53 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief cone UV mapping
 */
static void	set_cone_uv(t_record *p, t_cone *cone)
{
	double		theta;
	double		h;
	t_vector	temp;

	coordinates_set(&p->u_dir, &p->v_dir, &cone->normal);
	subtraction(&temp, &p->point, &cone->center);
	theta = atan2(-1 * dot_product(&temp, &p->v_dir), \
		dot_product(&temp, &p->u_dir)) + M_PI;
	h = dot_product(&temp, &cone->normal);
	p->u = theta * M_PI / 2 * 0.5;
	p->v = fmod_min(h);
}

/**
 * @brief sets new normal vector for record point
 */
static void	update_record_normal(t_record *record, t_cone *cone, double point)
{
	t_vector	temp;

	subtraction(&temp, &record->point, &cone->center);
	multiply_scalar(&record->normal, &cone->normal, \
		dot_product(&temp, &cone->normal));
	addition(&record->normal, &record->normal, &cone->center);
	subtraction(&record->normal, &record->point, &record->normal);
	unit_vector(&record->normal, &record->normal);
	multiply_scalar(&record->normal, &record->normal, point);
	multiply_scalar(&temp, &cone->normal, \
		(cone->radius * point / cone->height));
	addition(&record->normal, &record->normal, &temp);
	unit_vector(&record->normal, &record->normal);
}

/**
 * @brief registers hit point and updates record normal
 */
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
	set_hit_record_cone(record, cone);
	ray_at(&record->point, ray, root);
	subtraction(&temp, &record->point, &cone->center);
	point = dot_product(&temp, &cone->normal);
	if (point > cone->height || point < 0)
		return (false);
	point = cone->height - point;
	update_record_normal(record, cone, point);
	set_face_normal(ray, record);
	set_cone_uv(record, cone);
	set_hit_texture(record, &objects->texture);
	return (true);
}

/**
 * @brief cone-ray hit equation
 * @cite
 * a=(v⋅v)−m(v⋅ĥ )2−(v⋅ĥ )2
 * b=2[(v⋅w)−m(v⋅ĥ )(w⋅ĥ )−(v⋅ĥ )(w⋅ĥ )
 * c=(w⋅w)−m(w⋅ĥ )2−(w⋅ĥ )2
 */
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
	eq->a = length_sqrd(&ray->direction) - (1 + k) \
		* (dir_norm * dir_norm);
	eq->half_b = dir_oc - (1 + k) * dot_product(&oc, &cone->normal) \
		* dir_norm + k * cone->height * dir_norm;
	eq->c = length_sqrd(&oc) - (1 + k) * dot_product(&oc, &cone->normal) \
		* dot_product(&oc, &cone->normal) - cone->radius2 + \
			2 * k * cone->height * dot_product(&oc, &cone->normal);
	return (eq);
}

/**
 * @brief cone-ray intersection and hit vefification
 */
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
