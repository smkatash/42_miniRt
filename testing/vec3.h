/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:36:30 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 09:24:03 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>
#include <math.h>


typedef struct s_vec3 {
    double x;
    double y;
    double z;
}               t_vec3;

void* addition(t_vec3* new, const t_vec3* u, const t_vec3* v);
void* vector_add_t(t_vec3* new, const t_vec3* v, double s);
void* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v);
void* vector_minus_t(t_vec3* new, const t_vec3* v, double s);
void* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v);
void* vector_multiply_t(t_vec3* new, const t_vec3* v, double s);
void* vector_divide_t(t_vec3* new, const t_vec3* v, double s);
double  sum_one_vector(const t_vec3 *v);
double  dot_product(const t_vec3 *u, const t_vec3 *v);
void*  cross_product(t_vec3 *new, const t_vec3 *u, const t_vec3 *v);
void*  vector_set_each(t_vec3 *new, double x, double y, double z);
double length_sqrt(const t_vec3* v);
double length_v3(const t_vec3* v);
void* norm_vec3(t_vec3* res, const t_vec3* v);
void* unit_vector(t_vec3 *new, const t_vec3* v);


#endif
