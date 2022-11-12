/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:48:43 by ktashbae          #+#    #+#             */
/*   Updated: 2022/11/12 13:49:01 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (base * ft_pow(base, power - 1));
}
