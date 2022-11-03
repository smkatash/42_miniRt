/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:01:11 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/03 08:08:53 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parse.h"
# include "vector.h"

t_scene		*set_scene(int width, int height);
t_ambient	set_ambient(t_objlst *objects);
t_camera	set_camera(t_scene *scene, t_objlst *objects);
void		*set_light(t_scene *scene, t_objlst *objects);
t_sphere	*set_sphere(t_parse *parsed_objects);
t_plane 	*set_plane(t_parse *parsed_objects);
t_cylinder	*set_cylinder(t_parse *parsed_objects);
void	    *set_objects(t_scene *scene, t_objlst *object_list, void *mlx);
#endif