/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:01:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 10:39:11 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	*add_scalar(t_vector *vec, double t)
{
	vec->x += t;
	vec->y += t;
	vec->z += t;
	return (vec);
}

void	*minus_scalar(t_vector *vec, double t)
{
	vec->x -= t;
	vec->y -= t;
	vec->z -= t;
	return (vec);
}

void	*multiply_scalar(t_vector *vec, double t)
{
	vec->x *= t;
	vec->y *= t;
	vec->z *= t;
	return (vec);
}

void* divide_scalar(const t_vector *vec, double t) 
{
   if (t == 0)
   {
        ft_putstr_fd(2, "Floating point exception\n");
        exit(EXIT_FAILURE);
   }
   return (multiply_scalar(vec, 1/t));
}