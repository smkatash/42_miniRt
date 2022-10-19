/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:05:15 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/19 14:31:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "typedef.h"
# include "parse.h"
# include "scene.h"
# include "vector.h"
# include "../minilibx/mlx.h"

void    render_image(t_mlx *mlx, t_scene *scene);
void	*put_ray(t_ray *ray, t_camera *camera, double u, double v);


void    put_color(t_image *img, int h, int w, int color);
int     color(t_color pixel_color);

#endif
