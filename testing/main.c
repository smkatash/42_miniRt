/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 14:07:15 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

int main(void) 
{
    const int height = 256;
    const int width = 256;
    t_color   pxl_color;
    
    printf("P3\n%d %d\n255\n", width, height);
    for (int h = height - 1; h >= 0; --h) 
    {
        for (int w = 0; w < width; ++w) 
        {
            pxl_color.r = (double)w / (width - 1);
            pxl_color.g = (double)h / (height - 1);
            pxl_color.b = 0.25;
            put_color(&pxl_color);
        }
    }
    return (0);
}