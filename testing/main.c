/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 17:59:45 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_ray   put_ray(t_vec3 *or, t_vec3 *llc, t_vec3 *hor, t_vec3 *vert, double u, double v)
{
    t_vec3 u_hor = multipl_distance(u, hor);
    t_vec3 v_vert = multipl_distance(v, vert);
    t_vec3 sum = addition(llc, &u_hor);
    t_vec3 dir;
    t_ray ray;

    sum = addition(&sum, &v_vert);
    dir = substraction(&sum, or);
    ray.orig = *or;
    ray.dir = dir;
    return (ray);
}

t_color ray_color(t_ray *ray)
{
    t_color ray_color;
    t_vec3 unit_dir = unit_vector(&ray->dir);
    double t = 0.5 * (unit_dir.y + 1.0);
    double d = 1.0 - t;
    
    ray_color.r = (1.0 * d) + (0.5 * t);
    ray_color.g = (1.0 * d) + (0.7 * t);
    ray_color.b = (1.0 * d) + (1.0 * t);
    return (ray_color);
}

void    init_position(t_vec3 *pos, double x, double y, double z)
{
    pos->x = x;
    pos->y = y;
    pos->z = z;
}

int main(void) 
{
    t_color   pxl_color;
    t_vec3    origin;
    t_vec3    horizontal;
    t_vec3    vertical;
    t_vec3    focal;
    t_vec3    ptr;
    t_vec3    hold;
    t_vec3    hold1;
    t_vec3    lower_left_corner;
    double v;
    double  u;
    t_ray   ray;
    
    // Image
    const double ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int) width / ratio;
    // Camera
    double viewport_height = 2.0;
    double viewport_width = ratio * viewport_height;
    double focal_length = 1.0;
    
    init_position(&origin, 0, 0, 0);
    init_position(&horizontal, viewport_width, 0, 0);
    init_position(&vertical, 0, viewport_height, 0);
    init_position(&focal, 0, 0, focal_length);
    ptr = division(&horizontal, 2);
    hold = substraction(&origin, &ptr);
    ptr = division(&vertical, 2);
    hold1 = substraction(&ptr, &focal);
    lower_left_corner =  substraction(&hold, &hold1);

    // Render
    printf("P3\n%d %d\n255\n", width, height);
    for (int h = height - 1; h >= 0; --h) 
    {
        for (int w = 0; w < width; ++w) 
        {
            u = (double)w / (width - 1);
            v = (double)h / (height - 1);
            ray = put_ray(&origin, &lower_left_corner, &horizontal, &vertical, u, v);
            pxl_color = ray_color(&ray);
            put_color(&pxl_color);
        }
    }
    return (0);
}