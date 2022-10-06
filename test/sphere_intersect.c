/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:59:23 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/05 14:19:09 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
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
	b = 2 * (vec_dot_product(cam_sphere, ray));
	c = vec_dot_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return(0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return(1);
	return (0);
}
