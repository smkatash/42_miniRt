/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:21:01 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 10:44:12 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

static int  sphere_hit(const t_object* sphere, const t_ray* ray, 
                      double t_min, double t_max, t_object* record)
{
    t_vec3 oc;
    t_vec3 outward_normal;
    double a;
    double half_b;
    double c;
    double discriminant;
    double sqrd;
    double root;
    
    t_sphere *sph = (t_sphere *)sphere;
    substraction(&oc, &ray->origin, &sph->center);
    a = length_v3(&ray->dir);
    half_b = dot_product(&oc, &ray->dir);
    c = length_v3(&oc) - (sph->radius * sph->radius);
    discriminant = (half_b*half_b) - (a * c);
    if (discriminant < 0)
        return (0);
    sqrd = sqrt(discriminant);
    root = ((-1 * half_b) - sqrd) / a;
    if (root < t_min || t_max < root)
    {
        root = ((-1 * half_b) + sqrd) / a;
        if (root < t_min || t_max < root)
            return (0);
    }
    record->t = root;
    ray_at(&record->point, ray, record->t);
    substraction(&outward_normal, &record->point, &sph->center);
    vector_divide_t(&outward_normal, &outward_normal, sph->radius);
    record->set_face_normal(&record->normal, ray, &outward_normal);
    return (1);
}

void* sphere_init(t_sphere* sphere, t_vec3 center, double radius) 
{
    sphere->center = center;
    sphere->radius = radius;
    sphere->base.hit = &sphere_hit;
    return sphere;
}

