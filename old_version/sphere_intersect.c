/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:59:23 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/06 15:06:08 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)//should be float
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vector	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vec_subtract(cam->origin, sphere->center);
	b = 2 * (vec_dot_product(cam_sphere, ray));//formula intersection with sphere
	c = vec_dot_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);//if discr bigger 0 than it comes through the sphere, if it equals 0 it has touched sphere, if it's small 0-> didn't touch the sphere
	free(cam_sphere);
	if (discr < 0)
		return(0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;//the first point where ray cross the sphere
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;//the second point, where the ray goes out from the sphere
	if (dist_1 > 0)
		return(1);//should be in future dist, and than compare the dist, to find the closest one
	return (0);
}
