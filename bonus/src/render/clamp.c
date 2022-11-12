/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:14:37 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/12 12:13:21 by kanykei          ###   ########.fr       */
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
