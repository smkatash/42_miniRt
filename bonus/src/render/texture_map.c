/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:18:32 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/12 12:12:41 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief gets color based on uv coordinates of hit and texture
 */
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

/**
 * @brief normalizes color based TBN matrix multiplication my normal map
 * normal = texture(normalMap, fs_in.TexCoords).rgb;
 * normal = normal * 2.0 - 1.0;
 * normal = normalize(fs_in.TBN * normal); 
 */
t_vector	map_bump(t_record *record, t_texture *texture)
{
	int				v;
	int				u;
	unsigned int	pxl;
	t_matrix		tbn[3];
	t_vector		norm_color;

	v = (int)((1 - record->v) * texture->map->map->height);
	u = (int)(record->u * texture->map->map->width);
	pxl = xpm_color(texture->map->map, u, v);
	norm_color = pxl_to_color(pxl);
	multiply_scalar(&norm_color, &norm_color, 2);
	subtraction(&norm_color, &norm_color, &(t_vector){1, 1, 1});
	matrix_tbn(tbn, &record->u_dir, &record->v_dir, &record->normal);
	transpose(&norm_color, tbn, &norm_color);
	return (norm_color);
}
