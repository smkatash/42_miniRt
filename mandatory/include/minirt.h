/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/11/12 19:41:00 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <float.h>
# include <limits.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "../gnL/get_next_line.h"
# include "typedef.h"
# include "list.h"
# include "vector.h"
# include "render.h"
# include "parse.h"
# include "scene.h"

# define EPSILON 	1e-6
# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000
# define ESC		53

void	error_message(char *str);
void	error(void);

void	init_window(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		exit_window(int keycode, t_mlx *mlx);

#endif
