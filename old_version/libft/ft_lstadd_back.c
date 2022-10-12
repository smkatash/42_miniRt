/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:03:13 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/06 12:41:52 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst != NULL && new != NULL)
	{
		current = *lst;
		if (current != NULL)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
		else
			*lst = new;
	}
}
