/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:59:57 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/19 14:15:55 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static  void ray_trace(t_mlx *mlx, t_scene *scene, int h, int w)
{
    double		u;
	double		v;
    t_color     pixel_color;

    u = (double)w / (WIN_WIDTH - 1);
    v = (double)h / (WIN_HEIGHT - 1);
    put_ray(&scene->ray, scene->camera, u, v);
    color_ray(&pixel_color, scene);
    put_color(&mlx->img, mlx->win, WIN_HEIGHT - 1 - h, w, color(pixel_color));
}

static void free_scene(t_scene *scene)
{
    free_list(&scene->lights);
    free_list(&scene->objects);
    free(scene);
}

void    render_image(t_mlx *mlx, t_scene *scene)
{
    int h;
    int w;

    while (h >= 0)
    {
        w = 0;
        while (w < width)
        {
            ray_trace(mlx, scene, h, w);
            w++;
        }
        h--;
    }
    free_scene(scene);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}