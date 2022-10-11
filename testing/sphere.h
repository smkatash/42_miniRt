/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:18:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 10:36:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

typedef struct s_sphere {
    t_object base;
    t_vec3 center;
    double radius;
} t_sphere;

void* sphere_init(t_sphere* sphere, t_vec3 center, double radius);

#endif