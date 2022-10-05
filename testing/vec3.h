/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:48:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/05 23:16:11 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
} t_vec3;

typedef struct s_color
{
    double  r;
    double  g;
    double  b;
}   t_color;

typedef struct s_ray
{
    t_vec3  orig;
    t_vec3  dir;
}   t_ray;

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
t_vec3 division(t_vec3 *v, double t);

/**
 * @brief Color helper functions
 * */
void    put_color(t_color *pixels);

/**
 * @brief Ray helper functions
 * */
t_vec3  getRay_at(double t, t_ray *ray);
t_color ray_color(t_ray *ray);

/**
 * @brief Camera helper functions
 * */
void    init_position(t_vec3 *pos, double x, double y, double z);
void    init_lower_left(t_vec3 *lower_left_corner, t_vec3 *origin, t_vec3 *horizontal, t_vec3 *vertical, t_vec3 *focal);

/**
 * @brief Sphere helper functions
 * */
double    hitSphere(t_vec3 *center, double radius, t_ray *ray);

#endif
