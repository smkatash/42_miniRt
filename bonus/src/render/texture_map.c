/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:18:32 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/01 20:28:33 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

void	*map_image(t_record *record, t_objlst *objects)
{
	int		v;
	int		u;
	int		pxl;

	v = (int)(record->v * objects->texture.map->surface->height);
	u = (int)(record->u * objects->texture.map->surface->width);
	pxl = xpm_pixel_get(objects->texture.map->surface, u, v);
	record->color = pxl_to_color(pxl);
	return (&record->color);
}

void	*map_bump(t_record *record, t_objlst *objects)
{
	int		v;
	int		u;
	int		pxl;

	v = (int)((1 - record->v) * objects->texture.map->map->height);
	u = (int)(record->u * objects->texture.map->map->width);
	pxl = xpm_pixel_get(objects->texture.map->map, u, v);
	record->color = pxl_to_color(pxl);
	//what is next?
	return (&record->color);
}
