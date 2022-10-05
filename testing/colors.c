/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:47:16 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 15:54:27 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void    put_color(t_color *pixels)
{
    int x = pixels->r * 255.999;
    int y = pixels->g * 255.999;
    int z = pixels->b * 255.999;
    printf("%d %d %d\n", x, y, z);
}

t_vec3 getRay_at(double t, t_ray *ray)
{
    t_vec3 rayP;
    t_vec3 dist;

    dist =  multipl_distance(t, &ray->dir);
    rayP = addition(&ray->orig, &dist);
    return (rayP);
}