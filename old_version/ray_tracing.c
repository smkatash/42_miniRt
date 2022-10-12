/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:25:08 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/06 14:17:37 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y; // for function mlx_pixel_put
	float		x_angle;//width divide on 2, to become 0 in the middle of the screen
	float		y_angle;
	int			color;
	float		y_ray;//coordinates for the ray
	float		x_ray;
	t_vector	*ray;//ray from the camera
	t_vplane	*vplane;//imagine plane

	vplane = get_view_plane(scene->width, scene->hight, scene->cams->fov);
	mlx_y = 0;
	y_angle = (scene->hight / 2);
	while (y_angle >= (scene->hight / 2) * (-1))//while we dont come to the down corner, the last y
	{
		y_ray = y_angle * vplane->y_pixel;//movement on imagine plane
		x_angle = (scene->width / 2) * (-1);//we shuld recount x every time becuase we start the new line
		mlx_x = 0;
		while (x_angle <= scene->width / 2)//till we reach the right upper corner, last x
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);//direction is always -1 on z
			vec_normalize(ray);
			if(sphere_intersect(scene->cams, ray, scene->sphere))//if vector touch the sphere
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);//should go ftom 0
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}

}

t_vplane	*get_view_plane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float	aspect_ratio;

	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if(!vplane)
		error_exit(-1);
	aspect_ratio = width / hight;//соотношение насколько ширина больше высоты
	vplane->width = 1;//angle formular should be used instead
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;//1px in imagine plane to real window px
	vplane->y_pixel = vplane->hight / hight;
	return(vplane);
}
