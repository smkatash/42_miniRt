/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:50:06 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 23:01:23 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief create an object linked list
 */
t_objlst	*create_list(void *object, int type, t_color color)
{
	t_objlst	*new;

	new = ft_calloc(1, sizeof(t_objlst));
	if (!new)
		return (NULL);
	new->type = type;
	new->object = object;
	new->color = color;
	new->next = NULL;
	return (new);
}

/**
 * @brief insert and node into object list
 */
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

/**
 * @brief free object list
 */
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

/**
 * @brief free parsed list
 */
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
		free_parse_content(temp->object);
		free(temp->object);
		free(temp);
	}
}

/**
 * @brief count the size of a linked list
 */
int	list_size(t_objlst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
