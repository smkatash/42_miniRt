/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:22:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 12:44:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

void    *hit_object_type(t_hittable *func, t_objlst object)
{
    if (object.type == SPHERE)
		func = hit_sphere;
	if (object.type == PLANE)
		func = hit_plane;
	if (object.type == CYLINDER)
		func = hit_cylinder;
	return (NULL);
}

bool hit_object(t_objlst *objects, t_ray *ray, t_record *record)
{
    bool        hit_;
    t_hittable  object;

    hit_object_type(&object, *objects);
}

bool    hit(t_objlst *objects, t_ray *ray, t_record *record)
{
    bool        hit_;
    t_record    temp;

    hit_ = FALSE;
    temp = *record;
    while (objects)
    {
        if (hit_object(objects, ray, &temp))
        {
            hit_ = TRUE;
            temp.tmax = temp.t;
            *record = temp;
        }
        objects = objects->next;
    }
    return (hit_);
}