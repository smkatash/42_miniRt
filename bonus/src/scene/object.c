/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:55 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/31 17:05:39 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scene.h"

t_sphere	*set_sphere(t_objlst *parsed_objects)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = get_double_vector(parsed_objects->point, 0, 0);
	sphere->radius = get_double(parsed_objects->diameter, 0, INFINITY) / 2;
	sphere->radius2 = sphere->radius * sphere->radius;
	new_objects->type = SPHERE;
	sphere->kd = double_get(parsed_objects->KD, 0, 1);
	sphere->ks = double_get(parsed_objects->KS, 0, 1);
	sphere->ksn = double_get(parsed_objects->KSN, 0, INFINITY);
	return (sphere);
}

t_plane	*set_plane(t_objlst *parsed_objects)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = get_double_vector(parsed_objects->point, 0, 0);
	plane->normal = get_double_vector(parsed_objects->nor_vec, -1, 1);
	new_objects->type = PLANE;
	plane->kd = double_get(parsed_objects->KD, 0, 1);
	plane->ks = double_get(parsed_objects->KS, 0, 1);
	plane->ksn = double_get(parsed_objects->KSN, 0, INFINITY);
	return (plane);
}

void	*set_cylinder(t_objlst *parsed_objects)
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
	new_objects->type = CYLINDER;
	cylinder->kd = double_get(parsed_objects->KD, 0, 1);
	cylinder->ks = double_get(parsed_objects->KS, 0, 1);
	cylinder->ksn = double_get(parsed_objects->KSN, 0, INFINITY);
	return (scene);
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
		objects->color.color = get_int_vector(parsed_object->rgb, 0, 255);
	else if (parsed_object->text_type == CHECKBOARD)
	{
		objects->color.color = get_int_vector(parsed_object->rgb, 0, 255);
		objects->color.checkboard = malloc(sizeof(t_checkboard));
		if (!objects->color.checkboard)
			return ;
		objects->color.checkboard->xcolor = get_int_vector(parsed_object->xcolor, 0, 255);
		objects->color.checkboard->xheight = get_double(parsed_object->xheight, 0, INFINITY);
		objects->color.checkboard->xwidth = get_double(parsed_object->xwidth, 0, INFINITY);
	}
	else if (parsed_object->text_type == BUMPMAP)
	{
		objects->color.bumpmap = malloc(sizeof(t_bumpmap));
		if (!objects->color.bumpmap)
			return ;
		if (parsed_object->texture)
			objects->color.bumpmap->surface = load_image(parsed_object->texture_img, mlx);
		if (parsed_object->texture)
			objects->color.bumpmap->map = load_image(parsed_object->bump_img, mlx);
	}
}

void	set_objects(t_scene *scene, t_objlst *object_list, void *mlx)
{
	t_parse		*parsed_object;
	t_objlst	*new_objects;

	parsed_object = object_list->object;
	new_objects = malloc(sizeof(t_objlst));
	if (!new_objects)
		return (NULL);
	push_back(&scene->objects, new_objects);
	new_objects->type = parsed_object->type;
	if (new_objects->type == SPHERE)
		new_objects->object = set_sphere(parsed_object);
	else if (new_objects->type == PLANE)
		new_objects->object = set_plane(parsed_object);
	else if (new_objects->type == CYLINDER)
		new_objects->object = set_cylinder(parsed_object);
	set_texture(new_objects, parsed_object, mlx);
}
