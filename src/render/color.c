/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:45:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/20 22:58:03 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static double clamp(double x, double min, double max) 
{
	if (x < min)
		return (min);
	if (x > max)
		return max;
	return (x);
}

// Check again
int	color(t_color pixel_color)
{
	int	color;

	color = 0;
    pixel_color.x = 256 * clamp(pixel_color.x, 0.0, 0.999);
	pixel_color.y = 256 * clamp(pixel_color.y, 0.0, 0.999);
	pixel_color.z = 256 * clamp(pixel_color.z, 0.0, 0.999);
	return (color);
}

void    put_color(t_image *image, int h, int w, int color)
{
    char        *dst;

	dst = image->addr + (w * image->line + h * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
