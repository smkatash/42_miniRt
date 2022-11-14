/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:52:21 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 19:54:34 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief print into fd error message, exit
 */
void	error_message(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief set perror, exit
 */
void	error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

/**
 * @brief initialize mlx window and image
 */
void	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
}

/**
 * @brief close mlx window
 */
int	close_window(t_mlx *mlx)
{
	if (mlx->mlx != NULL)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	ft_putstr_fd("Exiting...\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * @brief exit mlx window on ESC key code
 */
int	exit_window(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		if (mlx->mlx != NULL)
		{
			mlx_destroy_image(mlx->mlx, mlx->img.img);
			mlx_destroy_window(mlx->mlx, mlx->win);
		}
		ft_putstr_fd("Exiting...\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
