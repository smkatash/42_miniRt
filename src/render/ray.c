/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:16:08 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/19 14:30:40 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

// ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
void	*put_ray(t_ray *ray, t_camera *camera, double u, double v)
{
    t_vector    temp;

    ray->origin = camera->origin;
    multiply_scalar(&ray->direction, &camera->horizontal, u);
    addition(&ray->direction, &camera->left_bottom, &ray->direction);
    multiply_scalar(&temp, &camera->vertical, v);
    addition(&ray->direction, &ray->direction, &temp);
    substraction(&ray->direction, &ray->direction, &camera->origin);
	return (ray);
}
