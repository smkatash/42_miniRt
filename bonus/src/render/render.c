/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:59:57 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/08 16:36:56 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ray_trace(t_mlx *mlx, t_scene *scene, int h, int w)
{
	double			u;
	double			v;
	t_color			pixel_color;
	unsigned int	pxl;

	u = (double)w / (WIN_WIDTH - 1);
	v = (double)h / (WIN_HEIGHT - 1);
	pixel_color = (t_color){0, 0, 0};
	put_ray(&scene->ray, &scene->camera, u, v);
	color_ray(&pixel_color, scene);
	pxl = color(&pixel_color);
	put_color(&mlx->img, w, WIN_HEIGHT - 1 - h, pxl);
}

static void	free_scene(t_scene *scene)
{
	free_list(&scene->lights);
	free_list(&scene->objects);
	free(scene);
}

void	render_image(t_mlx *mlx, t_scene *scene)
{
	int	h;
	int	w;

	h = WIN_HEIGHT - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < WIN_WIDTH)
		{
			ray_trace(mlx, scene, h, w);
			w++;
		}
		h--;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	free_scene(scene);
}
