/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:36 by kanykei           #+#    #+#             */
/*   Updated: 2022/11/14 20:10:29 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
 * @brief frees parse list of textures
 * @return 
 */
void	free_parse_texture(t_parse *parse)
{
	if (parse->texture_ident != NULL)
		free(parse->texture_ident);
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
	if (parse->kd != NULL)
		free(parse->kd);
	if (parse->ks != NULL)
		free(parse->ks);
	if (parse->ksn != NULL)
		free(parse->ksn);
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
		free_textures(temp->texture);
		free_parse_texture(temp->object);
		free_parse_content(temp->object);
		free(temp->object);
		free(temp);
	}
}
