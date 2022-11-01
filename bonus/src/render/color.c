/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:45:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/01 15:21:59 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static unsigned int	clamp(double c, int min, int max)
{
	unsigned int	pxl_clr;

	pxl_clr = (unsigned int)(256 * c);
	if (pxl_clr > max)
		pxl_clr = max;
	else if (pxl_clr < min)
		pxl_clr = min;
	return (pxl_clr);
}

unsigned int	color(t_color *pixel_color)
{
	unsigned int	color;

	color = 0 | clamp(pixel_color->x, 0, 255) << 16;
	color = color | clamp(pixel_color->y, 0, 255) << 8;
	color = color | clamp(pixel_color->z, 0, 255);
	return (color);
}

unsigned int	xpm_color(t_xpm_image *img, int x, int y)
{
	char	*dst;

	x = clamp(x, 0, img->width - 1);
	y = clamp(y, 0, img->height - 1);
	dst = img->data.addr + (y * img->data.line + x * (img->data.bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_color(t_image *image, int h, int w, unsigned int color)
{
	char	*dst;

	dst = image->addr + (w * image->line + h * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	*map_checkerboard(t_record *record, t_objlst *objects)
{
	int	v;
	int	u;

	v = floor(record->v * objects->texture.checkboard->height);
	u = floor(record->u * objects->texture.checkboard->width);
	if ((v + u) % 2)
		&record->color = objects->texture.color;
	else
		&record->color = objects->texture.checkboard->xcolor;
	return (record->color);
}

t_color	pxl_to_color(int pxl)
{
	double	r;
	double	g;
	double	b;

	r = (double)((pxl >> 16) & 255) / 256;
	g = (double)((pxl >> 8) & 255) / 256;
	b = (double)(pxl & 255) / 256;
	return ((t_color){r, g, b});
}

void	*map_image(t_record *record, t_objlst *objects)
{
	int		v;
	int		u;
	int		pxl;

	v = (int)(record->v * objects->texture.map->surface.height);
	u = (int)(record->u * objects->texture.map->surface.width);
	pxl = xpm_pixel_get(objects->texture.map->surface, u, v);
	&record->color = pxl_to_color(pxl);
	return (record->color);
}

void	*map_bump(t_record *record, t_objlst *objects)
{
	int		v;
	int		u;
	int		pxl;

	v = (int)((1 - record->v) * objects->texture.map->map.height);
	u = (int)(record->u * objects->texture.map->map.width);
	pxl = xpm_pixel_get(objects->texture.map->map, u, v);
	&record->color = pxl_to_color(pxl);
	//what is next?
	return (record->color);
}

void	set_hit_texture(t_record *record, t_objlst *objects)
{
	if (objects->texture.checkboard)
		map_checkerboard(record, objects);
	else if (objects->texture.map)
	{
		map_image(record, objects);
		if (objects->texture.map->map)
			map_bump(record, objects);
	}
	else
		record->color = objects->texture.color;
}