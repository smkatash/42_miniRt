/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkerboard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:21:38 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/01 20:30:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static void	*map_checkerboard(t_record *record, t_objlst *objects)
{
	int	v;
	int	u;

	v = floor(record->v * objects->texture.checkboard->xheight);
	u = floor(record->u * objects->texture.checkboard->xwidth);
	if ((v + u) % 2)
		record->color = objects->texture.color;
	else
		record->color = objects->texture.checkboard->xcolor;
	return (&record->color);
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
