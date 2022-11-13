/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:36 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/13 15:41:16 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief allocates memory for parse list
 * @return parse list
 */
t_parse	*new_parse_list(void)
{
	t_parse		*lst;

	lst = ft_calloc(1, sizeof(t_parse));
	if (!lst)
		return (NULL);
	return (lst);
}

/**
 * @brief frees memory of parse list
 * @return 
 */
void	free_parse_content(t_parse *parse)
{
	if (parse->ident != NULL)
		free(parse->ident);
	if (parse->bri_ratio != NULL)
		free(parse->bri_ratio);
	if (parse->point != NULL)
		free(parse->point);
	if (parse->nor_vec != NULL)
		free(parse->nor_vec);
	if (parse->diameter != NULL)
		free(parse->diameter);
	if (parse->height != NULL)
		free(parse->height);
	if (parse->fov != NULL)
		free(parse->fov);
	if (parse->rgb != NULL)
		free(parse->rgb);
}

/**
 * @brief frees array of strings
 * @return 
 */
t_parse	*free_split(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}
