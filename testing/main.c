/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/06 00:02:50 by kanykei          ###   ########.fr       */
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

int main(void) 
{
    t_color   pxl_color;
    t_vec3    origin;
    t_vec3    horizontal;
    t_vec3    vertical;
    t_vec3    focal;
    t_vec3    lower_left_corner;
    double v;
    double  u;
    t_ray   ray;
    
    // Image
    const double ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int) width / ratio;
    // Camera
    double viewport_height = 5.0;
    double viewport_width = ratio * viewport_height;
    double focal_length = 2.0;
    init_position(&origin, 0, 0, 0);
    init_position(&horizontal, viewport_width, 0, 0);
    init_position(&vertical, 0, viewport_height, 0);
    init_position(&focal, 0, 0, focal_length);
    init_lower_left(&lower_left_corner,&origin, &horizontal, &vertical, &focal);
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