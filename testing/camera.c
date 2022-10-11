/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:14:02 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 08:39:11 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera *set_camera(t_camera *cam, double ratio)
{
    t_vec3  temp;
    t_vec3  temp1;
    double viewport_height = 5.0;
    double viewport_width = ratio * viewport_height;
    double focal_length = 2.0;
    vector_set_each(&cam->origin, 0, 0, 0);
    vector_set_each(&cam->horizontal, viewport_width, 0, 0);
    vector_set_each(&cam->vertical, 0, viewport_height, 0);
    vector_set_each(&cam->focal, 0, 0, focal_length);
    
    vector_divide_t(&temp, &cam->horizontal, 2);
    substraction(&temp1, &cam->origin, &temp);
    vector_divide_t(&temp, &cam->vertical, 2);
    substraction(&cam->lower_left_corner, &temp1, &temp);
    vector_set_each(&temp, 0, 0, focal_length);
    substraction(&cam->lower_left_corner, &cam->lower_left_corner, &temp);
    return (cam);
}
