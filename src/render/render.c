/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:59:57 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/23 18:53:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static  void ray_trace(t_mlx *mlx, t_scene *scene, int h, int w)
{
    double		u;
	double		v;
    t_color     pixel_color;
    int         col;

    u = (double)w / (WIN_WIDTH - 1);
    v = (double)h / (WIN_HEIGHT - 1);
    put_ray(&scene->ray, &scene->camera, u, v);
    color_ray(&pixel_color, scene);
    col = color(pixel_color);
    put_color(&mlx->img, w, WIN_HEIGHT - 1 - h, col);
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