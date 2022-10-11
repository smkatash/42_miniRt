/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 15:30:01 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void* addition(t_vector* new, const t_vector* u, const t_vector* v) 
{
    new->x = u->x + v->x;
    new->y = u->y + v->y;
    new->z = u->z + v->z;
    return (new);
}

void* vector_add_t(t_vector* new, const t_vector* v, double t) 
{
    new->x = v->x + t;
    new->y = v->y + t;
    new->z = v->z + t;
    return (new);
}

void* substraction(t_vector* new, const t_vector* u, const t_vector* v) 
{
    new->x = u->x - v->x;
    new->y = u->y - v->y;
    new->z = u->z - v->z;
    return (new);
}

void* multiply(t_vector* new, const t_vector* u, const t_vector* v) 
{
    new->x = u->x * v->x;
    new->y = u->y * v->y;
    new->z = u->z * v->z;
    return (new);
}

void* vector_multiply_t(t_vector* new, const t_vector* v, double t) 
{
    new->x = t * v->x;
    new->y = t * v->y;
    new->z = t * v->z;
    return (new);
}

void* vector_divide_t(t_vector* new, const t_vector* v, double t) 
{
   return (vector_multiply_t(new, v, 1/t));
}

double sum_one_vector(const t_vector* v) 
{
    return (v->x + v->y + v->z);
}

double dot_product(const t_vector* u, const t_vector* v) 
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

double length_v3(const t_vector* v) 
{
    return (dot_product(v, v));
}

double length_sqrt(const t_vector* v) 
{
    return (sqrt(length_v3(v)));
}

void* unit_vector(t_vector *new, const t_vector* v) 
{
   double len = length_sqrt(v);
   return (vector_divide_t(new, v, len));
}

void* norm_vec3(t_vector* new, const t_vector* v) 
{
    return (vector_divide_t(new, v, length_sqrt(v)));
}

void *cross_product(t_vector* new, const t_vector* u, const t_vector* v) 
{
    new->x = (u->y*v->z) - (u->z*v->y);
    new->y = (u->z*v->x) - (u->x*v->z);
    new->z = (u->x*v->y) - (u->y*v->x);
    return (new);
}

void  *vector_set_each(t_vector *new, double x, double y, double z)
{
    new->x = x;
    new->y = y;
    new->z = z;
    return (new);
}
