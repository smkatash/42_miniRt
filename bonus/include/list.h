/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:51:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 20:09:26 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minirt_bonus.h"

// Objects list
t_objlst	*create_list(void *object, int type, t_color color);
void		push_back(t_objlst **lst, t_objlst *new);
void		free_parse_list(t_objlst **lst);
int			list_size(t_objlst *lst);
void		free_textures(t_texture	texture);
void		free_list(t_objlst **lst);

#endif
