/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:34:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 20:58:31 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void    init_position(t_vec3 *pos, double x, double y, double z)
{
    pos->x = x;
    pos->y = y;
    pos->z = z;
}

void init_lower_left(t_vec3 *lower_left_corner, t_vec3 *origin, t_vec3 *horizontal, t_vec3 *vertical, t_vec3 *focal)
{
    t_vec3    ptr;
    t_vec3    hold;
    t_vec3    hold1;

    ptr = division(horizontal, 2);
    hold = substraction(origin, &ptr);
    ptr = division(vertical, 2);
    hold1 = substraction(&ptr, focal);
    *lower_left_corner = substraction(&hold, &hold1);
}