/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:08 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/24 00:30:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static void init_record(t_record *record)
{
    record->tmin = EPSILON;
    record->tmax = INFINITY;
}

void    *color_ray(t_color *pxl, t_scene *scene)
{
    double  t;
    double  d;
    t_color temp;
    
    init_record(&scene->record);
    if (hit(scene->objects, &scene->ray, &scene->record))
        return (phong_model(scene, pxl));
    t = 0.5 * (scene->ray.direction.y + 1.0);
    d = 1.0 - t;
    multiply_scalar(&temp, &(t_color){1.0, 1.0, 1.0}, d);
    multiply_scalar(pxl, &(t_color){0.5, 0.7, 1.0}, t);
    addition(pxl, pxl, &temp);
    printf("%f %f %f\n", pxl->x, pxl->y, pxl->z);
    return (pxl);
}

// orig + t*dir
void    *ray_at(t_vector *point, t_ray *ray, double t)
{
    multiply_scalar(point, &ray->direction, t);
    addition(point, point, &ray->origin); 
    return (point);
}

// ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
void	*put_ray(t_ray *ray, t_camera *camera, double u, double v)
{
    t_vector    temp;

    ray->origin = camera->origin;
    multiply_scalar(&ray->direction, &camera->horizontal, u);
    addition(&ray->direction, &camera->left_bottom, &ray->direction);
    multiply_scalar(&temp, &camera->vertical, v);
    addition(&ray->direction, &ray->direction, &temp);
    subtraction(&ray->direction, &ray->direction, &camera->origin);
	return (ray);
}
