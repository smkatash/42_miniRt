/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:03:59 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 19:25:20 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minirt.h"

// Input parse
t_scene			*parse_input_set_scene(t_scene *scene, int fd);
int				get_input_file(int argv, char **argc);
void			*parse_to_scene(t_scene **scene, t_objlst *object_list);
t_parse			*new_parse_list(void);
void			free_parse_content(t_parse *parse);
t_parse			*free_split(char **str);
bool			valid_type(t_form type, t_type_data type_data);
bool			scan_elements(t_form type, char **str);
bool			elements_valid_count(t_objlst *objects);
t_form			element_type_set(char *s);

// Getters
double			get_double(const char *str, double min, double max);
struct s_vec3	get_int_vector(char *str, int min, int max);
struct s_vec3	get_double_vector(char *str, double min, double max);

#endif
