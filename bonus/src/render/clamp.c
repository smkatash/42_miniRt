/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:14:37 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 19:40:39 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/**
 * @brief clamps the value x to the range [min,max]
 */
unsigned int	clamp(double c, unsigned int min, unsigned int max)
{
	unsigned int	pxl_clr;

	pxl_clr = (unsigned int)(256 * c);
	if (pxl_clr > max)
		pxl_clr = max;
	else if (pxl_clr < min)
		pxl_clr = min;
	return (pxl_clr);
}

/**
 * @brief clamps the value x to the range [min,max]
 */
unsigned int	clamp_xpm(unsigned int pxl, unsigned int min, unsigned int max)
{
	if (pxl > max)
		pxl = max;
	else if (pxl < min)
		pxl = min;
	return (pxl);
}

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
 * @brief gets cone parameters into record
 */
void	set_hit_record_cone(t_record *record, t_cone *cone)
{
	record->ks = cone->ks;
	record->kd = cone->kd;
	record->ksn = cone->ksn;
	record->objects = cone;
}
