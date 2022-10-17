/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:36 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/17 14:59:30 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_parse	*new_parse_list(void)
{
	t_parse		*lst;

	lst = ft_calloc(sizeof(t_parse), 0);
	return (lst);
}

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

t_parse *free_split(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}