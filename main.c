/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/23 18:53:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"
#include "include/parse.h"
#include "include/scene.h"
#include "include/render.h"
#include "minilibx/mlx.h"

static void	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
}

static t_scene	*parse_input_set_scene(t_scene *scene, int fd)
{
	t_objlst	*object_list;
	
	object_list = NULL;
	parse_input_file(&object_list, fd);
	parse_to_scene(&scene, object_list);
	free_parse_list(&object_list);
	return (scene);
}

int	main(int argv, char **argc)
{
	int				fd;
	t_scene			*scene;
	t_mlx			mlx;

	scene = NULL;
	fd = get_input_file(argv, argc);
	scene = parse_input_set_scene(scene, fd);
	init_window(&mlx);
	render_image(&mlx, scene);
	// mlx_hook(mlx->win, X11_KEYPRESS, 1L << 0, key_press, mlx);
	// mlx_hook(mlx->win, X11_CLOSEBTN, 1L << 2, exit, mlx);
	mlx_loop(&mlx.mlx);
	return (0);
}