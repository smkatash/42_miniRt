/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/05 15:56:55 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"
#include <stdio.h>
#include <stdlib.h>

void	vector_setter(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

static t_vector	*vector_up(t_vector *vec)
{
	if (equal(vec, &(t_vector){0, 1, 0}))
		return (&(t_vector){0, 0, 1});
	if (equal(vec, &(t_vector){0, -1, 0}))
		return (&(t_vector){0, 0, -1});
	return (&(t_vector){0, 1, 0});
}

void	coordinates_set(t_vector *u, t_vector *v, t_vector *w)
{
	t_vector	temp;

	cross_product(&temp, vector_up(w), w);
	unit_vector(u, &temp);
	cross_product(&temp, w, u);
	unit_vector(v, &temp);
}
