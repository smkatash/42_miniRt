/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:14:38 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 08:15:50 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

typedef struct s_camera {
    t_vec3 origin;
    t_vec3 horizontal;
    t_vec3 vertical;
    t_vec3 lower_left_corner;
    t_vec3 focal;
}   t_camera;

t_camera *set_camera(t_camera *cam, double ratio);

#endif