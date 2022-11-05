/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:18:32 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/05 20:14:08 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

t_color	map_image(t_record *record, t_texture *texture)
{
	int				v;
	int				u;
	unsigned int	pxl;
	t_color			color;

	v = (int)((1 - record->v) * texture->map->surface->height);
	u = (int)(record->u * texture->map->surface->width);
	pxl = xpm_color(texture->map->surface, u, v);
	color = pxl_to_color(pxl);
	return (color);
}

// normal = texture(normalMap, fs_in.TexCoords).rgb;
// normal = normal * 2.0 - 1.0;   
// normal = normalize(fs_in.TBN * normal); 
t_vector	map_bump(t_record *record, t_texture *texture)
{
	int				v;
	int				u;
	unsigned int	pxl;
	t_matrix		TBN[3];
	t_vector		norm_color;

	v = (int)((1 - record->v) * texture->map->map->height);
	u = (int)(record->u * texture->map->map->width);
	pxl = xpm_color(texture->map->map, u, v);
	norm_color = pxl_to_color(pxl);
	multiply_scalar(&norm_color, &norm_color, 2);
	subtraction(&norm_color, &norm_color, &(t_color){1, 1, 1});
	matrix_tbn(TBN, &record->u_dir, &record->v_dir, &record->normal);
	transpose(&norm_color, TBN, &norm_color);
	return (norm_color);
}
