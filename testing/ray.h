/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:46:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 08:21:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "color.h"
#include "camera.h"

typedef struct s_ray{
    t_vec3 origin;
    t_vec3 dir;
}       t_ray;

int     ray_at(t_vec3* pos, const t_ray* ray, double t);
t_color* ray_color(t_color *color, const t_ray *ray);
t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v);

#endif