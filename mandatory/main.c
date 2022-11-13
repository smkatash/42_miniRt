/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:28:22 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/13 19:28:00 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks_check(void)
{
	system("leaks miniRT");
}

void	free_alloced_memory(t_garbage *ptr)
{
	free(ptr->ptr);
	free(ptr->line);
	free_parse_list((t_objlst **)ptr->parse_objects);
}

int	main(int argv, char **argc)
{
	int			fd;
	t_mlx		mlx;
	t_scene		*scene;

	atexit(leaks_check);
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
