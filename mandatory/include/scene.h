/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:01:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 01:10:45 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_scene		*set_scene(int width, int height);
t_ambient	set_ambient(t_objlst *objects);
t_camera	set_camera(t_scene *scene, t_objlst *objects);
void		*set_light(t_scene *scene, t_objlst *objects);
void		*set_sphere(t_scene *scene, t_objlst *objects);
void		*set_plane(t_scene *scene, t_objlst *objects);
void		*set_cylinder(t_scene *scene, t_objlst *objects);

#endif