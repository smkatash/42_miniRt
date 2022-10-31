/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:04:58 by annaiarinov       #+#    #+#             */
/*   Updated: 2022/04/06 12:07:34 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
		t_list *head;

		head = (t_list *)malloc(sizeof(t_list));
		if (head == NULL)
			return (NULL);
		head->content = content;
		head->next = NULL;
		return (head);
}
