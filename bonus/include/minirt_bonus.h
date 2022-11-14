/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/12 20:54:07 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

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
# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000
# define ESC		53

// Error handling
void	error_message(char *str);
void	error(void);

// MLX utils
void	init_window(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		exit_window(int keycode, t_mlx *mlx);

#endif
