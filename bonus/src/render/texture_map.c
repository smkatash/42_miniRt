/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:18:32 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/02 22:07:01 by kanykei          ###   ########.fr       */
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

// normal = texture(normalMap, fs_in.TexCoords).rgb;
// normal = normal * 2.0 - 1.0;   
// normal = normalize(fs_in.TBN * normal); 
void	*map_bump(t_record *record, t_objlst *objects)
{
	int			v;
	int			u;
	int			pxl;
	t_matrix	TBN;

	v = (int)((1 - record->v) * objects->texture.map->map->height);
	u = (int)(record->u * objects->texture.map->map->width);
	pxl = xpm_pixel_get(objects->texture.map->map, u, v);
	record->color = pxl_to_color(pxl);
	multiply_scalar(&record->color, &record->color, 2);
	subtraction(&record->color, &record->color, &(t_color){1, 1, 1});
	matrix_tbn(&TBN, &record->u_dir, &record->v_dir, &record->normal);
	transpose(&record->color, &TBN, &record->normal);
	return (&record->color);
}
