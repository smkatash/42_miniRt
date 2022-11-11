/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/10 17:23:43 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argv, char **argc)
{
	int		fd;
	t_scene	*scene;
	t_mlx	mlx;

	fd = get_input_file(argv, argc);
	scene = NULL;
	init_window(&mlx);
	scene = parse_input_set_scene(scene, fd);
	render_image(&mlx, scene);
	mlx_key_hook(mlx.win, exit_window, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, close_window, "Exiting...");
	mlx_loop(&mlx.mlx);
	return (0);
}
