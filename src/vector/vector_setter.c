/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:31:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 10:39:14 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	vector_setter(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}