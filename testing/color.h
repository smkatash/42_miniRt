/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:44:05 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 07:45:25 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

#include "vec3.h"

typedef t_vec3 t_color;

void    put_color(t_vec3 *pixels);

#endif