/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:31:59 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/04 13:57:02 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"
# include <math.h>

# define IMG_HEIGHT 600
# define IMG_WIDTH 600

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;


typedef struct	s_v3
{
	float x;
	float y;
	float z;
}				t_v3;

typedef struct	s_sph
{
	t_v3	center;
	float	diametr;
}				t_sph;

typedef struct my_mlx
{
	void			*mlx_win;
	void			*mlx_ptr;
	void			*mlx_img;
	char			*mlx_data_addr;
	unsigned int	win_width;
	unsigned int	win_heigh;

}	t_my_mlx;

#endif
