/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:15:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 10:43:43 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"

typedef struct s_object t_object;

struct s_object {
    t_vec3 point;
    t_vec3 normal;
    double t;
    int(*hit)(const t_object*, const t_ray*, double, double, t_object*);
    void(*set_face_normal)(t_object*, const t_ray*, const t_vec3*);
    int front;
};

inline void set_face_normal(t_object* object, const t_ray* r,
                                   const t_vec3* outwardNormal) 
{
    object->front = dot_product(&r->dir, outwardNormal) < 0;
    object->normal = *outwardNormal;
    if (!object->front) 
        vector_multiply_t(&object->normal, &object->normal, -1);
}

#endif
