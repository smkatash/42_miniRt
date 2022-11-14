/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:15:38 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 14:13:32 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief set ambient parameters
 * @return ambient struct
 */
t_ambient	set_ambient(t_objlst *objects)
{
	t_parse		*parsed_list;
	t_ambient	ambient;

	parsed_list = objects->object;
	ambient.light_ratio = get_double(parsed_list->bri_ratio, 0.0, 1.0);
	ambient.light_color = get_int_vector(parsed_list->rgb, 0, 255);
	return (ambient);
}
