/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:50:06 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/17 15:00:19 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

t_objlst    *create_list(void *object, int type, t_color color)
{
	t_objlst	*new;

	new = ft_calloc(sizeof(t_objlst), 0);
	new->type = type;
	new->object = object;
	new->color = color;
	new->next = NULL;
	return (new);
}

void	push_back(t_objlst **lst, t_objlst *new)
{
	t_objlst	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->next = NULL;
	return ;
}

void	free_list(t_objlst **lst)
{
	t_objlst	*temp;
	t_objlst	*head;

	head = *lst;
	*lst = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->object);
		free(temp);
	}
}

void	free_parse_list(t_objlst **lst)
{
	t_objlst	*temp;
	t_objlst	*head;

	head = *lst;
	*lst = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		free_parse_list(temp->object);
		free(temp->object);
		free(temp);
	}
}

int	list_size(t_objlst *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
