/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/05 20:14:56 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_sphere	*set_sphere(t_parse *parsed_objects)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = get_double_vector(parsed_objects->point, 0, 0);
	sphere->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	sphere->kd = get_double(parsed_objects->KD, 0, 1);
	sphere->ks = get_double(parsed_objects->KS, 0, 1);
	sphere->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (sphere);
}

t_plane	*set_plane(t_parse *parsed_objects)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	plane->kd = get_double(parsed_objects->KD, 0, 1);
	plane->ks = get_double(parsed_objects->KS, 0, 1);
	plane->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (plane);
}

t_cylinder	*set_cylinder(t_parse *parsed_objects)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->center = get_double_vector(parsed_objects->point, 0, 0);
	cylinder->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	cylinder->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	cylinder->radius2 = cylinder->radius * cylinder->radius;
	cylinder->height = get_double(parsed_objects->height, 0, INFINITY);
	cylinder->kd = get_double(parsed_objects->KD, 0, 1);
	cylinder->ks = get_double(parsed_objects->KS, 0, 1);
	cylinder->ksn = get_double(parsed_objects->KSN, 0, INFINITY);
	return (cylinder);
}

t_xpm_image	*load_image(char *file, void *mlx)
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

void	*set_objects(t_scene **scene, t_objlst *object_list, void *mlx)
{
	t_parse		*parsed_object;
	t_objlst	*new_objects;

	parsed_object = object_list->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	new_objects->type = parsed_object->type;
	if (new_objects->type == SPHERE)
		new_objects->object = set_sphere(parsed_object);
	else if (new_objects->type == PLANE)
		new_objects->object = set_plane(parsed_object);
	else if (new_objects->type == CYLINDER)
		new_objects->object = set_cylinder(parsed_object);
	set_texture(new_objects, parsed_object, mlx);
	push_back(&(*scene)->objects, new_objects);
	return (scene);
}
