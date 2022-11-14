/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:59:57 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 19:19:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief colors pxl of a ray hit
 * @cite two offsets along the screen sides,
 * to move the ray endpoint across the screen
 */
static void	ray_trace(t_mlx *mlx, t_scene *scene, int h, int w)
{
	double			u;
	double			v;
	t_color			pixel_color;
	unsigned int	col;

	u = (double)w / (WIN_WIDTH - 1);
	v = (double)h / (WIN_HEIGHT - 1);
	pixel_color = (t_color){0, 0, 0};
	put_ray(&scene->ray, &scene->camera, u, v);
	color_ray(&pixel_color, scene);
	col = color(&pixel_color);
	put_color(&mlx->img, w, WIN_HEIGHT - 1 - h, col);
}

/**
 * @brief frees scene
 */
static void	free_scene(t_scene *scene)
{
	free_list(&scene->lights);
	free_list(&scene->objects);
	free(scene);
}

/**
 * @brief sends the ray through the scene
 */
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
