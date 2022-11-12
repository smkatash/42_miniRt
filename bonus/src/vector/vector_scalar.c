/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:01:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 00:57:10 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief adding scalar to a vector
 */
void	*add_scalar(t_vector *new, const t_vector *vec, double t)
{
	new->x = vec->x + t;
	new->y = vec->y + t;
	new->z = vec->x + t;
	return (new);
}

/**
 * @brief subtracting scalar from a vector
 */
void	*minus_scalar(t_vector *new, const t_vector *vec, double t)
{
	new->x = vec->x - t;
	new->y = vec->y - t;
	new->z = vec->x - t;
	return (new);
}

/**
 * @brief multiplying a vector by scalar
 */
void	*multiply_scalar(t_vector *new, const t_vector *vec, double t)
{
	new->x = vec->x * t;
	new->y = vec->y * t;
	new->z = vec->z * t;
	return (new);
}

/**
 * @brief dividing a vector by scalar
 */
void	*divide_scalar(t_vector *new, const t_vector *vec, double t)
{
	if (t == 0)
	{
		ft_putstr_fd("Floating point exception\n", 2);
		exit(EXIT_FAILURE);
	}
	return (multiply_scalar(new, vec, 1 / t));
}
