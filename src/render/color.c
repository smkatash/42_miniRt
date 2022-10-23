/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:45:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/22 18:58:35 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static unsigned int clamp(double c) 
{
	int	pxl_clr;

	pxl_clr = (unsigned int)(256  * c);
	if (pxl_clr > 255)
		pxl_clr = 255;
	return (pxl_clr);
}

// Check again
unsigned int	color(t_color pixel_color)
{
	unsigned int	color;

   	color = 0 | clamp(pixel_color.x) << 16;
	color = 0 | clamp(pixel_color.y) << 8;
	color = clamp(pixel_color.z);
	return (color);
}

void    put_color(t_image *image, int h, int w, int color)
{
    char        *dst;

	dst = image->addr + (w * image->line + h * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
