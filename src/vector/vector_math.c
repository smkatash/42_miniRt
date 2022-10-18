/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:16:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 13:06:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void    *addition(t_vector *new, const t_vector *u, const t_vector *v)
{
    new->x = u->x + v->x;
    new->y = u->y + v->y;
    new->z = u->z + v->z;
    return (new);
}

void    *subtraction(t_vector *new, const t_vector *u, const t_vector *v)
{
    new->x = u->x - v->x;
    new->y = u->y - v->y;
    new->z = u->z - v->z;
    return (new);
}

void    *multiply(t_vector *new, const t_vector *u, const t_vector *v)
{
    new->x = u->x * v->x;
    new->y = u->y * v->y;
    new->z = u->z * v->z;
    return (new);
}

double  dot_product(const t_vector *u,const t_vector *v)
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

void  *cross_product(t_vector *new, const t_vector *u, const t_vector *v)
{
    new->x = (u->y * v->z) - (u->z * v->y);
	new->y = (u->z * v->x) - (u->x * v->z);
	new->z = (u->x * v->y) - (u->y * v->x);
    return (new);
}