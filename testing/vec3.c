/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 16:35:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double length_squared(double x, double y, double z) 
{
    return ((x*x) + (y*y) + (z*z));
}

double length(double x, double y, double z) 
{
    return (sqrt(length_squared(x, y , z)));
}

t_vec3  addition(t_vec3 *u, t_vec3 *v)
{
    t_vec3 sum;
    
    sum.x = u->x + v->x;
    sum.y = u->y + v->y;
    sum.z = u->z + v->z;
    return sum;
}

t_vec3  substraction(t_vec3 *u, t_vec3 *v)
{
    t_vec3 substr;
    
    substr.x = u->x - v->x;
    substr.y = u->y - v->y;
    substr.z = u->z - v->z;
    return substr;
}

t_vec3  multipl(t_vec3 *u, t_vec3 *v)
{
    t_vec3 m;
    
    m.x = u->x * v->x;
    m.y = u->y * v->y;
    m.z = u->z * v->z;
    return m;
}

t_vec3  multipl_distance(double t, t_vec3 *v)
{
    t_vec3 dist;
    
    dist.x = t * v->x;
    dist.y = t * v->y;
    dist.z = t * v->z;
    return (dist);
}

double  dot(t_vec3 *u, t_vec3 *v)
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

t_vec3  cross(t_vec3 *u, t_vec3 *v)
{
    t_vec3 cr;
    cr.x = (u->y * v->z) - (u->z * v->y);
    cr.y = (u->z * v->x) - (u->x * v->z);
    cr.z = (u->x * v->y) - (u->y * v->x);
    return (cr);
}

t_vec3 unit_vector(t_vec3 *v) 
{
    t_vec3  uv;
    double  len;
    
    len = length(v->x, v->y, v->z);
    uv = multipl_distance(1/len, v);
    return (uv);
}

t_vec3 division(t_vec3 *v, double t)
{
    return (multipl_distance(1/t, v));
}
