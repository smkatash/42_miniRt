/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checkerboard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:21:38 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/14 11:44:34 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief gets color based on uv coordinates and checkerboard
 * @cite That uv_pattern_at() function will multiply u 
 * and v by (respectively) the width and height of the pattern, 
 * round each down to the nearest whole number, and add them together. 
 * If the result modulo 2 is zero, return color_a. 
 * Otherwise, return color_b.
 */
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

/**
 * @brief sets textures based on input type
 */
void	set_hit_texture(t_record *record, t_texture *texture)
{
	if (texture->checkboard != NULL)
		record->color = map_checkerboard(record, texture);
	else if (texture->map != NULL)
	{
		record->color = map_image(record, texture);
		if (texture->map->map != NULL)
			record->normal = map_bump(record, texture);
	}
	else
		record->color = texture->color;
}
