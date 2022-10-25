/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/25 10:20:17 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"
#include "include/parse.h"
#include "include/scene.h"
#include "include/render.h"
#include "minilibx/mlx.h"

int	main(int argv, char **argc)
{
	int		fd;
	t_scene	*scene;
	t_mlx	mlx;

	fd = get_input_file(argv, argc);
	scene = NULL;
	scene = parse_input_set_scene(scene, fd);
	init_window(&mlx);
	render_image(&mlx, scene);
	mlx_key_hook(mlx.win, exit_window, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), close_window, "Exiting...");
	mlx_loop(&mlx.mlx);
	return (0);
}
