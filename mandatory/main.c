/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/14 20:22:27 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	leaks_check(void)
// {
// 	system("leaks miniRT");
// }

int	main(int argv, char **argc)
{
	int			fd;
	t_mlx		mlx;
	t_scene		*scene;

	//atexit(leaks_check);
	scene = NULL;
	fd = get_input_file(argv, argc);
	init_window(&mlx);
	scene = parse_input_set_scene(scene, fd);
	render_image(&mlx, scene);
	mlx_key_hook(mlx.win, exit_window, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, close_window, &mlx);
	mlx_loop(&mlx.mlx);
	return (0);
}
