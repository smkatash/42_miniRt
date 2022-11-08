/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_hyperboloid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:49:15 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 17:43:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	set_hyperboloid_uv(t_record *p, t_hyper *hp)
{
	double		theta;
	double		h;
	t_vector	temp;

	coordinates_set(&p->u_dir, &p->v_dir, &hp->normal);
	subtraction(&temp, &p->point, &hp->center);
	theta = atan2(-1 * dot_product(&temp, &p->v_dir), dot_product(&temp, &p->u_dir)) + M_PI;
	h = dot_product(&temp, &hp->normal);
	p->u = theta * M_1_PI * 0.5;
	p->v = fmod_min(h);
}

static void	set_hit_record(t_record *record, t_hyper *hp)
{
	record->ks = hp->ks;
	record->kd = hp->kd;
	record->ksn = hp->ksn;
	record->objects = hp;
}

static bool	hit_point(t_objlst *objects, t_ray *ray, t_record *record,
					double root)
{
	t_hyper		*hp;
	double		point;

	if (isnan(root) || root > record->tmax || root < record->tmin)
		return (false);
	hp = (t_hyper *)objects->object;
	record->t = root;
	set_hit_record(record, hp);
	ray_at(&record->point, ray, root);
	point = fabs(record->point.y - hp->center.y);
	if (point >= hp->height / 2 || point < 0)
		return (false);
	unit_vector(&record->normal, &record->normal);
	set_face_normal(ray, record);
	set_hyperboloid_uv(record, hp);
	set_hit_texture(record, &objects->texture);
	return (true);
}

static void	*intersection(t_equation *eq, t_objlst *objects, t_ray *ray)
{
	t_hyper		*hp;
	t_vector	oc;
	t_vector	new_dir;
	t_vector	center_dir;
	t_vector	new_center;
	t_vector	abc2;

	hp = (t_hyper *)objects->object;
	subtraction(&oc, &ray->origin, &hp->center);
	new_dir.x = ray->direction.x * ray->direction.x;
	new_dir.y = ray->direction.y * ray->direction.y;
	new_dir.z = ray->direction.z * ray->direction.z;
	center_dir.x = ray->direction.x * hp->center.x;
	center_dir.y = ray->direction.y * hp->center.y;
	center_dir.z = ray->direction.z * hp->center.z;
	new_center.x = hp->center.x * hp->center.x;
	new_center.y = hp->center.y * hp->center.y;
	new_center.z = hp->center.z * hp->center.z;
	abc2.x = 1 / hp->normal.x * hp->normal.x;
	abc2.y = -1 / hp->normal.y * hp->normal.y;
	abc2.z = 1 / hp->normal.z * hp->normal.z;
	eq->a = dot_product(&new_dir, &abc2);
	eq->half_b = dot_product(&center_dir, &abc2);
	eq->c = dot_product(&new_center, &abc2) - hp->radius;
	return (eq);
}

bool	hit_hyperboloid(t_objlst *objects, t_ray *ray, t_record *record)
{
	t_equation	eq;

	intersection(&eq, objects, ray);
	if (hit_point(objects, ray, record, nearest_root(&eq, 0)))
		return (true);
	if (hit_point(objects, ray, record, nearest_root(&eq, 1)))
		return (true);
	return (false);
}
