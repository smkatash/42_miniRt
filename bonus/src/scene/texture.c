/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:52:41 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 21:10:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

static t_xpm_image	*load_image(char *file, void *mlx)
{
	t_xpm_image	*img;

	img = malloc(sizeof(t_xpm_image));
	if (!img)
		return (NULL);
	if (ft_strlen(file) < 4)
		error_message("Wrong format image file [.xpm] \n");
	if (ft_strcmp(&file[ft_strlen(file) - 4], ".xpm") != 0)
		error_message("Wrong format image file [.xpm] \n");
	img->data.img = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
	if (!img->data.img)
		error_message("Failed to load [.xpm] image file\n");
	img->data.addr = mlx_get_data_addr(img->data.img, &img->data.bpp, &img->data.line, &img->data.endian);
	return (img);
}

void	set_texture(t_objlst *objects, t_parse *parsed_object, void *mlx)
{
	if (parsed_object->text_type == COLOR)
	{
		objects->texture.color = get_int_vector(parsed_object->rgb, 0, 255);
		objects->texture.checkboard = NULL;
		objects->texture.map = NULL;
	}
	else if (parsed_object->text_type == CHECKBOARD)
	{
		objects->texture.color = get_int_vector(parsed_object->rgb, 0, 255);
		objects->texture.checkboard = malloc(sizeof(t_checkboard));
		if (!objects->texture.checkboard)
			return ;
		objects->texture.checkboard->xcolor = get_int_vector(parsed_object->xcolor, 0, 255);
		objects->texture.checkboard->xheight = get_double(parsed_object->xheight, 0, INFINITY);
		objects->texture.checkboard->xwidth = get_double(parsed_object->xwidth, 0, INFINITY);
		objects->texture.map = NULL;
	}
	else if (parsed_object->text_type == BUMPMAP)
	{
		objects->texture.map = malloc(sizeof(t_bumpmap));
		objects->texture.map->surface = load_image(parsed_object->texture_img, mlx);
		if (parsed_object->bump_img)
			objects->texture.map->map = load_image(parsed_object->bump_img, mlx);
		else
			objects->texture.map->map = NULL;
		objects->texture.checkboard = NULL;
	}
}