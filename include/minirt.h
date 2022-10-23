/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/22 18:31:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000

void	error_message(char *str);
void	error(void);

// void	error_exit(int code);

// t_vector	*new_vector(float x, float y, float z);
// t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2);
// float	vec_length(t_vector *vec);
// void	vec_normalize(t_vector *vec);
// float	vec_dot_product(t_vector *vec1, t_vector *vec2);

// t_camera	*new_cam(t_vector *origin, t_vector *direction, float fov);

// t_sphere	*new_sphere(t_vector *center, float radius);
// t_scene	*new_scene(t_camera *cam, t_sphere *sphere);
// t_vplane	*get_view_plane(float width, float hight, float fov);
// int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere);

// void	ray_tracing(void *mlx, void *window, t_scene *scene);
#endif
