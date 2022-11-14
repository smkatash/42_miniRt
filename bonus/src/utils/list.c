/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:50:06 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 20:13:59 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
	new->texture.color = color;
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

void	free_textures(t_texture	texture)
{
	if (texture.checkboard != NULL)
		free(texture.checkboard);
	if (texture.map != NULL)
	{
		if (texture.map->surface != NULL)
		{
			if (texture.map->surface->data.img != NULL)
				free(texture.map->surface->data.img);
			free(texture.map->surface);
		}
		if (texture.map->map != NULL)
		{
			if (texture.map->map->data.img)
				free(texture.map->map->data.img);
			free(texture.map->map);
		}
		free(texture.map);
	}
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
		free_textures(temp->texture);
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
