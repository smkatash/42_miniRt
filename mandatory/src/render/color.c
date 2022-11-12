/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:45:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 03:29:09 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief clamps the value x to the range [min,max]
 */
static unsigned int	clamp(double c)
{
	unsigned int	pxl_clr;

	pxl_clr = (unsigned int)(256 * c);
	if (pxl_clr > 255)
		pxl_clr = 255;
	return (pxl_clr);
}

/**
 * @brief encode RGB colors
 * @cite int RGB = (alpha << 24);
 * RGB = RGB | (red << 16);
 * RGB = RGB | (green << 8);
 * RGB = RGB | (blue);
 */
unsigned int	color(t_color *pixel_color)
{
	unsigned int	color;

	color = 0 | clamp(pixel_color->x) << 16;
	color = color | clamp(pixel_color->y) << 8;
	color = color | clamp(pixel_color->z);
	return (color);
}

/**
 * @brief sets color by modifying image data
 */
void	put_color(t_image *image, int h, int w, unsigned int color)
{
	char	*dst;

	dst = image->addr + (w * image->line + h * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
