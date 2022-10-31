/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:25:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/25 10:21:58 by aiarinov         ###   ########.fr       */
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

void	*unit_vector(t_vector *new, t_vector *vec)
{
	return (divide_scalar(new, vec, length(vec)));
}

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
