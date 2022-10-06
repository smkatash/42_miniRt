/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:13:57 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/05 12:16:35 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera *new_cam(t_vector *origin, t_vector *direction, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		error_exit(-1);
	cam->origin = origin;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}
