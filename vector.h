/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:36:30 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 15:29:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <math.h>

typedef struct s_vector {
    float x;
    float y;
    float z;
}				t_vector;

void* addition(t_vector* new, const t_vector* u, const t_vector* v);
void* vector_add_t(t_vector* new, const t_vector* v, double s);
void* substraction(t_vector* new, const t_vector* u, const t_vector* v);
void* vector_minus_t(t_vector* new, const t_vector* v, double s);
void* multiply(t_vector* new, const t_vector* u, const t_vector* v);
void* vector_multiply_t(t_vector* new, const t_vector* v, double s);
void* vector_divide_t(t_vector* new, const t_vector* v, double s);
double  sum_one_vector(const t_vector *v);
double  dot_product(const t_vector *u, const t_vector *v);
void*  cross_product(t_vector *new, const t_vector *u, const t_vector *v);
void*  vector_set_each(t_vector *new, double x, double y, double z);
double length_sqrt(const t_vector* v);
double length_v3(const t_vector* v);
void* norm_vec3(t_vector* res, const t_vector* v);
void* unit_vector(t_vector *new, const t_vector* v);


#endif
