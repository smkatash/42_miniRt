/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:18:32 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/05 17:50:34 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

t_color	map_image(t_record *record, t_objlst *objects)
{
	int				v;
	int				u;
	unsigned int	pxl;
	t_color			color;

	printf("IN\n");
	v = (int)((1 - record->v) * objects->texture.map->surface->height);
	u = (int)(record->u * objects->texture.map->surface->width);
	printf("IMG: %d and %d\n", v, u);
	pxl = xpm_color(objects->texture.map->surface, u, v);
	color = pxl_to_color(pxl);
	return (color);
}

// normal = texture(normalMap, fs_in.TexCoords).rgb;
// normal = normal * 2.0 - 1.0;   
// normal = normalize(fs_in.TBN * normal); 
t_vector	map_bump(t_record *record, t_objlst *objects)
{
	int				v;
	int				u;
	unsigned int	pxl;
	t_matrix		TBN;
	t_vector		norm_color;

	v = (int)((1 - record->v) * objects->texture.map->map->height);
	u = (int)(record->u * objects->texture.map->map->width);
	pxl = xpm_color(objects->texture.map->map, u, v);
	norm_color = pxl_to_color(pxl);
	multiply_scalar(&norm_color, &norm_color, 2);
	subtraction(&norm_color, &norm_color, &(t_color){1, 1, 1});
	matrix_tbn(&TBN, &record->u_dir, &record->v_dir, &record->normal);
	transpose(&norm_color, &TBN, &norm_color);
	return (norm_color);
}
