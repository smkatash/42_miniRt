/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkerboard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:21:38 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/05 20:13:54 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static t_color	map_checkerboard(t_record *record, t_texture *texture)
{
	int	v;
	int	u;

	v = floor(record->v * texture->checkboard->xheight);
	u = floor(record->u * texture->checkboard->xwidth);
	if ((v + u) % 2)
		return (texture->color);
	else
		return (texture->checkboard->xcolor);
}

void	set_hit_texture(t_record *record, t_texture *texture)
{
	if (texture->checkboard)
	{
		record->color = map_checkerboard(record, texture);
	}
	else if (texture->map)
	{
		record->color = map_image(record, texture);
		if (texture->map->map)
			record->normal = map_bump(record, texture);
	}
	else
		record->color = texture->color;
}