/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:25:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 23:27:57 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

bool    hit_plane(t_objlst *objects, t_ray *ray, t_record *record)
{
    t_plane     *plane;
    double      denominator;
    double      num;
    t_vector    temp;
    double      root;

    plane = (t_plane *)objects->object;
    denominator = dot_product(&ray->direction, &plane->normal);
    if (denominator == 0)
        return (false);
    subtraction(&temp, &ray->origin, &plane->point);
    num = dot_product(&temp, &plane->normal) * -1;
    root = num / denominator;
    if (root > record->tmax || root < record->tmin)
        return (false);
    record->t = root;
    ray_at(&record->point, ray, root);
    record->normal = plane->normal;
    set_face_normal(ray, record);
    record->color = objects->color;
    return (true);
}
