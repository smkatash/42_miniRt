/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:14:37 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 00:51:50 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

unsigned int	clamp_xpm(unsigned int pxl, unsigned int min, unsigned int max)
{
	if (pxl > max)
		pxl = max;
	else if (pxl < min)
		pxl = min;
	return (pxl);
}
