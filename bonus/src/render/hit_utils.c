/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:54:44 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/12 15:05:15 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief computes the floating-point remainder of the division operation
 * for scalar
 */
double	fmod_min(double t)
{
	t = fmod(t, 1);
	if (t < 0)
		return (t + 1);
	return (t);
}

/**
 * @brief computes the floating-point remainder of the division operation
 * for vectors
 */
double	fmod_dot(t_vector *v, t_vector *u)
{
	double	t;

	t = fmod(dot_product(v, u), 1);
	if (t < 0)
		return (t + 1);
	return (t);
}

/**
 * @brief gets plane parameters into record
 */
void	set_hit_record(t_record *record, t_cone *cone)
{
	record->ks = cone->ks;
	record->kd = cone->kd;
	record->ksn = cone->ksn;
	record->objects = cone;
}
