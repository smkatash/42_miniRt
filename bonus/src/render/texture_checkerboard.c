/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkerboard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:21:38 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/05 17:57:34 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static t_color	map_checkerboard(t_record *record, t_objlst *objects)
{
	int	v;
	int	u;

	printf("CHECK\n");
	v = floor(record->v * objects->texture.checkboard->xheight);
	u = floor(record->u * objects->texture.checkboard->xwidth);
	printf("1\n");
	if ((v + u) % 2)
		return (objects->texture.color);
	else
		return (objects->texture.checkboard->xcolor);
}

void	set_hit_texture(t_record *record, t_objlst *objects)
{
	if (objects->texture.checkboard != NULL)
		record->color = map_checkerboard(record, objects);
	else if (objects->texture.map != NULL)
	{
		printf("MAP: %d %d\n", objects->texture.map->surface->height, objects->texture.map->surface->width);
		record->color = map_image(record, objects);
		printf("%f %f %f\n", record->color.x, record->color.y, record->color.z);
		if (objects->texture.map->map)
			record->normal = map_bump(record, objects);
	}
	else
		record->color = objects->texture.color;
}
