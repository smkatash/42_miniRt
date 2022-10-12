/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:03:59 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/12 16:28:26 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "typedef.h"
# include "minirt.h"
# include "../libft/libft.a"

int             get_input_file(int argv, char **argc);
t_scene         *parse_to_scene(t_objlst *object_list);
t_parse         *new_parse_list(void);
t_objlst        *parse_input_file(int fd);
void            free_parse_list(t_parse *parse);
t_parse         *free_split(char **str);
bool	        valid_type(t_form type, t_type_data type_data);
bool            scan_elements(t_form type, char **str);
bool            elements_valid_count(t_objlst *objects);

#endif