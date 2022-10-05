/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:47:16 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/06 00:07:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void    put_color(t_color *pixels)
{
    int x = pixels->r * 255.999;
    int y = pixels->g * 255.999;
    int z = pixels->b * 255.999;
    printf("%d %d %d\n", x, y, z);
}

t_vec3 getRay_at(double t, t_ray *ray)
{
    t_vec3 rayP;
    t_vec3 dist;

    dist =  multipl_distance(t, &ray->dir);
    rayP = addition(&ray->orig, &dist);
    return (rayP);
}

t_color ray_color(t_ray *ray)
{
    t_vec3  P;
    t_color ray_color;
    t_vec3  rayAt;
    t_vec3  unV;
    t_vec3  N;
    P.x = 0;
    P.y = 0;
    P.z = 1;
    double shadeSphere = hitSphere(&P, 0.7, ray);
    if (shadeSphere > 0.0)
    {
        rayAt = getRay_at(shadeSphere, ray);
        unV = substraction(&rayAt, &P);
        N = unit_vector(&unV);
        ray_color.r = 0.5 * (N.x + 1);
        ray_color.g = 0.5 * (N.y + 1);
        ray_color.b = 0.7 * (N.z + 2);
        return (ray_color);
    }
    t_vec3 unit_dir = unit_vector(&ray->dir);
    double t = 0.5 * (unit_dir.y + 1.0);
    double d = 1.0 - t;
    ray_color.r = (1.0 * d) + (0.2 * t);
    ray_color.g = (1.0 * d) + (0.5 * t);
    ray_color.b = (1.0 * d) + (1.0 * t);
    return (ray_color);
}