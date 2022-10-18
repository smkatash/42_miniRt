/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:16:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 10:39:04 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void    *addition(t_vector *u, t_vector *v)
{
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    return (u);
}

void    *subtraction(t_vector *u, t_vector *v)
{
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    return (u);
}

void    *multiply(t_vector *u, t_vector *v)
{
    u->x *= v->x;
    u->y *= v->y;
    u->z *= v->z;
    return (u);
}

double  dot_product(t_vector *u, t_vector *v)
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

void  *cross_product(t_vector *u, t_vector *v)
{
    t_vector    new;
    new.x = u->y * v->z - u->z * v->y;
	new.y = u->z * v->x - u->x * v->z;
	new.z = u->x * v->y - u->y * v->x;
    return (new);
}