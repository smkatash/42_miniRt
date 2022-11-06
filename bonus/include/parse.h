/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:03:59 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 21:02:53 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "typedef.h"
# include "scene.h"
# include "minirt.h"
# include "list.h"
# include "../libs/libft/libft.h"

// Objects
t_scene	        *parse_input_set_scene(t_scene *scene, int fd, void	*mlx);
int				get_input_file(int argv, char **argc);
void	        *parse_to_scene(t_scene **scene, t_objlst *object_list, void *mlx);
t_parse			*new_parse_list(void);
void			*parse_input_file(t_objlst **objects, int fd);
bool			valid_type(t_form type, t_type_data type_data);
bool			scan_elements(t_form type, char **str);
bool			elements_valid_count(t_objlst *objects);
t_form			element_type_set(char *s);

// Texture
void			parse_texture(t_parse *lst, char **str, int i);

// Getters
double			get_double(const char *str, double min, double max);
struct s_vec3	get_int_vector(char *str, int min, int max);
struct s_vec3	get_double_vector(char *str, double min, double max);

// Free memory
void			free_parse_content(t_parse *parse);
t_parse			*free_split(char **str);

#endif
