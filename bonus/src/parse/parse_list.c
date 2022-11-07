/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:36 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/06 23:00:46 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parse	*new_parse_list(void)
{
	t_parse		*lst;

	lst = malloc(sizeof(t_parse));
	if (!lst)
		return (NULL);
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
	if (parse->KD != NULL)
		free(parse->KD);
	if (parse->KS != NULL)
		free(parse->KS);
	if (parse->KSN != NULL)
		free(parse->KSN);
}

void	free_parse_texture(t_parse *parse)
{
	if (parse->ident != NULL)
		free(parse->ident);
	if (parse->texture_img != NULL)
		free(parse->texture_img);
	if (parse->bump_img != NULL)
		free(parse->bump_img);
	if (parse->xcolor != NULL)
		free(parse->xcolor);
	if (parse->xwidth != NULL)
		free(parse->xwidth);
	if (parse->xheight != NULL)
		free(parse->xheight);
}

t_parse	*free_split(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx] != NULL)
		free(str[idx++]);
	free(str);
	return (NULL);
}
