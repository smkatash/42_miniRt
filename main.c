/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/17 14:00:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"
#include "include/parse.h"
#include "include/scene.h"
#include "minilibx/mlx.h"

static void	init_window(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx, scene->screen.width, scene->screen.height);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
}

static t_scene	*parse_input_set_scene(t_scene *scene, int fd)
{
	t_objlst	*object_list;
	
	object_list = NULL;
	parse_input_file(object_list, fd);
	parse_to_scene(scene, object_list);
	//del_obj_lst_parse(&object_list);
	return (scene);
}

int	main(int argv, char **argc)
{
	int				fd;
	t_scene			*scene;
	t_mlx			*mlx;

	fd = get_input_file(argv, argc);
	scene = NULL;
	mlx = NULL;
	parse_input_set_scene(scene, fd);
	init_window(mlx, scene);
	// Function to draw scene
	// mlx_hook(mlx.win, X11_KEYPRESS, 1L << 0, key_press, &mlx);
	// mlx_hook(mlx.win, X11_CLOSEBTN, 1L << 2, exit, &mlx);
	// mlx_loop(mlx.mlx);
	return (0);
}