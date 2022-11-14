/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:52:41 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 16:02:22 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief loads xpm image into image struct with mlx
 */
static t_xpm_image	*load_image(char *file, void *mlx)
{
	t_xpm_image	*img;

	img = ft_calloc(1, sizeof(t_xpm_image));
	if (!img)
		return (NULL);
	if (ft_strlen(file) < 4)
		error_message("Wrong format image file [.xpm]\n");
	if (ft_strcmp(&file[ft_strlen(file) - 4], ".xpm") != 0)
		error_message("Wrong format image file [.xpm]\n");
	img->data.img = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
	if (!img->data.img)
		error_message("Failed to load [.xpm] image file\n");
	img->data.addr = mlx_get_data_addr(img->data.img, \
		&img->data.bpp, &img->data.line, &img->data.endian);
	return (img);
}

/**
 * @brief sets RGB color texture
 */
static void	set_texture_color(t_objlst *objects, t_parse *parsed_object)
{
	objects->texture.color = get_int_vector(parsed_object->rgb, 0, 255);
	objects->texture.checkboard = NULL;
	objects->texture.map = NULL;
}

/**
 * @brief sets checkboard parameters
 */
static void	set_texture_checkboard(t_objlst *objects, t_parse *parsed_object)
{
	objects->texture.color = get_int_vector(parsed_object->rgb, 0, 255);
	objects->texture.checkboard = ft_calloc(1, sizeof(t_checkboard));
	if (!objects->texture.checkboard)
		return ;
	objects->texture.checkboard->xcolor = \
		get_int_vector(parsed_object->xcolor, 0, 255);
	objects->texture.checkboard->xheight = \
		get_double(parsed_object->xheight, 0, INFINITY);
	objects->texture.checkboard->xwidth = \
		get_double(parsed_object->xwidth, 0, INFINITY);
	objects->texture.map = NULL;
}

/**
 * @brief sets bump textures by image loading with mlx ptr
 */
static void	set_texture_bummap(t_objlst *objects, t_parse *parsed_object, \
	void *mlx)
{
	objects->texture.map = ft_calloc(1, sizeof(t_bumpmap));
	if (parsed_object->texture_img != NULL)
	{
		objects->texture.map->surface = \
			load_image(parsed_object->texture_img, mlx);
		if (parsed_object->bump_img != NULL)
			objects->texture.map->map = \
				load_image(parsed_object->bump_img, mlx);
		else
			objects->texture.map->map = NULL;
	}
	objects->texture.checkboard = NULL;
}

/**
 * @brief sets textures according to texture type
 */
void	set_texture(t_objlst *objects, t_parse *parsed_object, void *mlx)
{
	if (parsed_object->text_type == COLOR)
		set_texture_color(objects, parsed_object);
	else if (parsed_object->text_type == CHECKBOARD)
		set_texture_checkboard(objects, parsed_object);
	else if (parsed_object->text_type == BUMPMAP)
		set_texture_bummap(objects, parsed_object, mlx);
}
