/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/07 00:56:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdbool.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnL/get_next_line.h"
# include "typedef.h"
# include "parse.h"
# include "scene.h"
# include "render.h"
# include "list.h"
# include "vector.h"

# define EPSILON 	1e-6
# define WIN_WIDTH	800
# define WIN_HEIGHT	800
# define ESC		53

// Error handling
void	error_message(char *str);
void	error(void);

// MLX utils
void	init_window(t_mlx *mlx);
int		close_window(char *message);
int		exit_window(int keycode, t_mlx *mlx);

#endif
