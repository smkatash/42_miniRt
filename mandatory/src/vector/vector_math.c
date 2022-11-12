/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:16:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 00:46:00 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief adding vectors
 */
void	*addition(t_vector *new, const t_vector *u, const t_vector *v)
{
	new->x = u->x + v->x;
	new->y = u->y + v->y;
	new->z = u->z + v->z;
	return (new);
}

/**
 * @brief substracting vectors
 */
void	*subtraction(t_vector *new, const t_vector *u, const t_vector *v)
{
	new->x = u->x - v->x;
	new->y = u->y - v->y;
	new->z = u->z - v->z;
	return (new);
}

/**
 * @brief multiplying two vectors
 */
void	*multiply(t_vector *new, const t_vector *u, const t_vector *v)
{
	new->x = u->x * v->x;
	new->y = u->y * v->y;
	new->z = u->z * v->z;
	return (new);
}

/**
 * @brief multiplying vectors using Dot Product
 * @cite a · b = |a| × |b| × cos(θ)
 */
double	dot_product(const t_vector *u, const t_vector *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

/**
 * @brief multiplying vectors using Cross Product
 * @cite a × b = |a| |b| sin(θ) n
 */
void	*cross_product(t_vector *new, const t_vector *u, const t_vector *v)
{
	new->x = (u->y * v->z) - (u->z * v->y);
	new->y = (u->z * v->x) - (u->x * v->z);
	new->z = (u->x * v->y) - (u->y * v->x);
	return (new);
}
