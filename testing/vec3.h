/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:48:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 13:58:11 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
#define VEC3_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
} t_vec3;

typedef struct s_point
{
    t_vec3 points;
} t_point;

typedef struct s_color
{
    double  r;
    double  g;
    double  b;
}   t_color;

/**
 * @brief Vector helper functions
 * */
double length_squared(double x, double y, double z);
double length(double x, double y, double z);
t_vec3 addition(t_vec3 *u, t_vec3 *v);
t_vec3 substraction(t_vec3 *u, t_vec3 *v);
t_vec3  multipl(t_vec3 *u, t_vec3 *v);
t_vec3  multipl_distance(double t, t_vec3 *v);
double  dot(t_vec3 *u, t_vec3 *v);
t_vec3  cross(t_vec3 *u, t_vec3 *v);
t_vec3 unit_vector(t_vec3 *v);

/**
 * @brief Color helper functions
 * */
void    put_color(t_color *pixels);

#endif