/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:45:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 03:31:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

	color = 0 | clamp(pixel_color->x, 0, 255) << 16;
	color = color | clamp(pixel_color->y, 0, 255) << 8;
	color = color | clamp(pixel_color->z, 0, 255);
	return (color);
}

/**
 * @brief clamps xpm, 
 * @cite dst = address that represents the begining of 
 * the memory area where the image is stored.
 * bpp = bits represent the color of the first pixel in 
 * the first line of the image.
 */
unsigned int	xpm_color(t_xpm_image *img, int x, int y)
{
	char	*dst;

	x = clamp_xpm(x, 0, img->width - 1);
	y = clamp_xpm(y, 0, img->height - 1);
	dst = img->data.addr + (y * img->data.line + x * (img->data.bpp / 8));
	return (*(unsigned int *)dst);
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

/**
 * @brief decode RGB colors to doubles
 * @cite int RGB = (alpha << 24);
 * RGB = RGB | (red << 16);
 * RGB = RGB | (green << 8);
 * RGB = RGB | (blue);
 */
t_color	pxl_to_color(unsigned int pxl)
{
	t_color	rgb;

	rgb.x = (double)((int)(pxl >> 16) & 255) / 256;
	rgb.y = (double)((int)(pxl >> 8) & 255) / 256;
	rgb.z = (double)((int)pxl & 255) / 256;
	return (rgb);
}
