/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:43:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 08:39:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "ray.h"

int main(void) 
{
   t_camera  camera;
   t_color   pxl_color;
   t_ray   ray;
   double v;
   double  u;
    
    // Image
    const double ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int) width / ratio;

    // Camera
    set_camera(&camera, ratio);

    // Render
    printf("P3\n%d %d\n255\n", width, height);
    for (int h = height - 1; h >= 0; --h) 
    {
        for (int w = 0; w < width; ++w) 
        {
            u = (double)w / (width - 1);
            v = (double)h / (height - 1);
            put_ray(&ray, &camera, u, v);
            ray_color(&pxl_color, &ray);
            put_color(&pxl_color);
        }
    }
    return (0); 
}