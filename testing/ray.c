/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:46:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 10:25:15 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stdbool.h>
#include <math.h>

int ray_at(t_vec3* pos, const t_ray* ray, double t) 
{
    vector_multiply_t(pos, &ray->dir, t);
    addition(pos, &ray->origin, pos);
    return 1;
}

t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v)
{
    t_vec3 temp;
    t_vec3 direction;
    
    ray->origin = cam->origin;
    vector_multiply_t(&temp, &cam->horizontal, u);
    addition(&direction, &cam->lower_left_corner, &temp);
    vector_multiply_t(&temp, &cam->vertical, v);
    addition(&direction, &direction, &temp);
    substraction(&direction, &direction, &ray->origin);
    ray->dir = direction;
    return (ray);
}

t_color *ray_color(t_color *color, const t_ray *ray)
{
    t_color     color_temp;
    t_vec3      unit_dir;
    t_vec3      point;
    double      t;
    double      d;
    
    vector_set_each(&point, 0,0,-1);
    t = hit_sphere(&point, 0.7, ray);
    if (t > 0.0)
    {
        ray_at(&unit_dir, ray, t);
        substraction(&unit_dir, &unit_dir, &point);
        color->x = (unit_dir.x + 1) * 0.5;
        color->y = (unit_dir.y + 1) * 0.5;
        color->z = (unit_dir.z + 1) * 0.5;
        return (color);
    }
    unit_vector(&unit_dir, &ray->dir);
    t = 0.5 * (unit_dir.y + 1.0);
    d = 1.0 - t;
    vector_set_each(&color_temp, 1.0, 1.0, 1.0);
    vector_multiply_t(color, &color_temp, d);
    vector_set_each(&color_temp, 0.5, 0.7, 1.0);
    vector_multiply_t(&color_temp, &color_temp, t);
    addition(color, color, &color_temp);
    return (color);
}
