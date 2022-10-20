/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:22:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 23:08:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

double  nearest_root(t_equation *eq, int range)
{
    double  discriminant;
    double  sqrtd;
    double  root;

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

void	set_face_normal(t_ray *ray, t_record *record)
{
	record->front_face = dot_product(&ray->direction, &record->normal) < 0;
	if (record->front_face == false)
		multiply_scalar(&record->normal, &record->normal, -1);
}

static void    *hit_object_type(t_objlst object)
{
    if (object.type == SPHERE)
		return (hit_sphere);
	if (object.type == PLANE)
		return (hit_plane);
	if (object.type == CYLINDER)
		return (hit_cylinder);
	return (false);
}

static bool hit_object(t_objlst *objects)
{
    bool        hit_;

    hit_ = hit_object_type(*objects);
    return (hit_);
}

bool    hit(t_objlst *objects, t_record *record)
{
    bool        hit_;
    t_record    temp;

    hit_ = false;
    temp = *record;
    while (objects)
    {
        if (hit_object(objects))
        {
            hit_ = true;
            temp.tmax = temp.t;
            *record = temp;
        }
        objects = objects->next;
    }
    return (hit_);
}