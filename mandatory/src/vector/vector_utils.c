/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:25:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 03:09:58 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief checks of vectors are equal
 * @return true/false
 */
bool	equal(t_vector *u, t_vector *v)
{
	if (u->x == v->x && u->y == v->y && u->z == v->z)
		return (true);
	return (false);
}

/**
 * @brief sum of vector squared
 */
double	length_sqrd(t_vector *vec)
{
	return ((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

/**
 * @brief magnitude of a vector
 */
double	length(t_vector *vec)
{
	return (sqrt(length_sqrd(vec)));
}

/**
 * @brief vector with magnitude == 1
 */
void	*unit_vector(t_vector *new, t_vector *vec)
{
	return (divide_scalar(new, vec, length(vec)));
}

/**
 * @brief sets vector to minimum parameters of two vectors
 */
void	*minimum(t_vector *new, t_vector *u, t_vector *v)
{
	new = u;
	if (u->x > v->x)
		new->x = v->x;
	if (u->y > v->y)
		new->y = v->y;
	if (u->z > v->z)
		new->z = v->z;
	return (new);
}
