/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:34:24 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/05 11:52:42 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*new_vector(float x, float y, float z)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		error_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return(vec);
}

t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2)
{
	t_vector	*result;
	result = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return(result);
}

float	vec_length(t_vector *vec)
{
	float	result;

	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return(result);
}

void	vec_normalize(t_vector *vec)
{
	float	length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

//скалярное произведение двух векторов
float	vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return(result);
}
