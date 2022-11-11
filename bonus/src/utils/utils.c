/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:52:21 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/11 01:21:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT_bonus");
}

int	close_window(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_SUCCESS);
}

int	exit_window(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == ESC)
	{
		if (mlx->mlx != NULL)
			mlx_destroy_window(mlx->mlx, mlx->win);
	}
	ft_putstr_fd("Exiting...\n", 1);
	exit(EXIT_SUCCESS);
}
