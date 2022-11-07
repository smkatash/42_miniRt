/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:51:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/07 01:09:03 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minirt.h"

t_objlst	*create_list(void *object, int type, t_color color);
void		push_back(t_objlst **lst, t_objlst *new);
void		free_list(t_objlst **lst);
void		free_parse_list(t_objlst **lst);
int			list_size(t_objlst *lst);

#endif
