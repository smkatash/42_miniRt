/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrix_tbn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:16:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/02 22:05:56 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	*matrix_tbn(t_matrix *m, t_vector *v1, t_vector *v2, t_vector *v3)
{
	m[0][0] = v1->x;
	m[0][1] = v2->x;
	m[0][2] = v3->x;
	m[1][0] = v1->y;
	m[1][1] = v2->y;
	m[1][2] = v3->y;
	m[2][0] = v1->z;
	m[2][1] = v2->z;
	m[2][2] = v3->z;
	return (m);
}

void	*transpose(t_vector *new, t_matrix *m, t_vector *v)
{
	new->x = (m[0][0] * v->x) + (m[0][1] * v->y) + (m[0][2] * v->z);
	new->y = (m[1][0] * v->x) + (m[1][1] * v->y) + (m[1][2] * v->z);
	new->z = (m[2][0] * v->x) + (m[2][1] * v->y) + (m[2][2] * v->z);
	return (new);
}
