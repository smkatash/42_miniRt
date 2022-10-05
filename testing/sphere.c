/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:57:29 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/06 00:17:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double  hitSphere(t_vec3 *center, double radius, t_ray *ray)
{
    double  x;
    double  half_y;
    double  z;
    double  discriminant;
    t_vec3  oc = substraction(&ray->orig, center);
    x = length_squared(ray->dir.x, ray->dir.y, ray->dir.z);
    half_y = dot(&oc, &ray->dir);
    z = length_squared(oc.x, oc.y, oc.z) - (radius * radius);
    discriminant = (half_y * half_y) - (x * z);
    if (discriminant < 0)
    {
        return (-1.0);
    }
    else
    {
        return ((-half_y - sqrt(discriminant)) / x);
    }
}
