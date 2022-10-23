/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:05:15 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/23 18:50:48 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "typedef.h"
# include "parse.h"
# include "scene.h"
# include "vector.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdbool.h>

void    render_image(t_mlx *mlx, t_scene *scene);

void	*put_ray(t_ray *ray, t_camera *camera, double u, double v);
void    *ray_at(t_vector *point, t_ray *ray, double t);
void    *color_ray(t_color *pxl, t_scene *scene);
void    *phong_model(t_scene *scene, t_color *pxl);
bool    overcast_shadow(t_scene *scene, t_vector *light_dir, double t);
void    *lambertian_diffuse(t_scene *scene, t_objlst *lights, t_vector *light_dir, t_color *diff_comp);
void    *phong_specular(t_scene *scene, t_objlst *lights, t_vector *light_dir, t_color *spec_com);

void    put_color(t_image *image, int h, int w, int color);
unsigned int     color(t_color pixel_color);

void	set_face_normal(t_ray *ray, t_record *record);
double  nearest_root(t_equation *eq, int range);
bool    hit(t_objlst *objects, t_record *record);
bool    hit_sphere(t_objlst *objects, t_ray *ray, t_record *record);
bool    hit_plane(t_objlst *objects, t_ray *ray, t_record *record);
bool    hit_cylinder(t_objlst *objects, t_ray *ray, t_record *record);

#endif
