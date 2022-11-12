/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 01:00:36 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief sets coordinates of a vector
 */
void	vector_setter(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

/**
 * @brief sets coordinates of a vector to upper direction
 */
static t_vector	*vector_up(t_vector vec)
{
	if (equal(&vec, &(t_vector){0, 1, 0}))
		return (&(t_vector){0, 0, 1});
	if (equal(&vec, &(t_vector){0, -1, 0}))
		return (&(t_vector){0, 0, -1});
	return (&(t_vector){0, 1, 0});
}

/**
 * @brief resets coordinates by unit vector from its cross product
 */
void	coordinates_set(t_vector *u, t_vector *v, t_vector *w)
{
	t_vector	temp;

	unit_vector(u, cross_product(&temp, vector_up(*w), w));
	unit_vector(v, cross_product(&temp, w, u));
}
