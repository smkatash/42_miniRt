/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:25:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 10:39:20 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

bool	equal(t_vector *u, t_vector *v)
{
	if (u->x == v->x && u->y == v->y && u->z == v->z)
		return (true);
	return (false);
}

double	length_sqrd(t_vector *vec)
{
	return ((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

double	length(t_vector *vec)
{
	return (sqrt(length_sqrd(vec)));
}

void	*unit_vector(t_vector *vec)
{
	return (divide_scalar(vec, length(vec)));
}

void	*minimum(t_vector *u, t_vector *v)
{
	if (u->x > v->x)
		u->x = v->x;
	if (u->y > v->y)
		u->y = v->y;
	if (u->z > v->z)
		u->z = v->z;
	return (u);
}