/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:01:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/18 10:36:42 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parse.h"
# include "vector.h"

t_scene		*set_scene(int width, int height);
t_ambient	ambient_set(t_objlst *objects);
t_camera	camera_set(t_scene *scene, t_objlst *objects);
void		light_set(t_scene *scene, t_objlst *objects);
void		sphere_set(t_scene *scene, t_objlst *objects);
void		plane_set(t_scene *scene, t_objlst *objects);
void		cylinder_set(t_scene *scene, t_objlst *objects);

#endif